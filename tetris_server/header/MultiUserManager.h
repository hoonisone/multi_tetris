#pragma once
#include "MultiUserDao.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
/*
항상 모든 유저의 최신 정보를 userList에 담고 있다.
매번 userDao를 통해 파일에 기록한다.
*/
class UserManager {
private:
	MultiUserDao* userDao;
	map<string, int> userMap;	// userList의 idx와 이름을 연결지어줌 -> 빠른 탐색을 위함
	vector<MultiUser> userList;
	void updateFile() {
		userDao->setAllUsers(userList);
	}
public:
	UserManager(MultiUserDao* userDao) : userDao(userDao) {
		userList = userDao->getAllUsers();
		for (int i = 0; i < userList.size(); i++) {
			MultiUser& user = userList[i];
			userMap[user.getName()] = i;	// 이름과 인덱스를 연결 짓는다.
		}
	}
	vector<string> getAllUserNames() const{
		vector<string> names;
		for (int i = 0; i < userList.size(); i++) {
			names.push_back(userList[i].getName());
		}
		return names;
	}
	bool nameExistCheck(string name) const {
		return userMap.find(name) == userMap.end();
	}
	bool objectExistCheck(MultiUser user) {
		return nameExistCheck(user.getName());
	}
	void insertUser(MultiUser user){
		if (!objectExistCheck(user)) {
			userList.push_back(user);
			userMap[user.getName()] = userList.size() - 1;
		}
	}
	void update(MultiUser user) {
		if (objectExistCheck(user)) {
			userList[userMap[user.getName()]] = user;
			updateFile();
		}
	}

};