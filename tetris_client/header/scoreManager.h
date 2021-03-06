#pragma once

#include "scoreBoard.h"

class ScoreManager {
private:
	ScoreBoard* scoreBoard;
	//ScoreBoard* scoreBoard;
	int drawX, drawY;
	int level, line, block;
	long long score;
	int lineScore() {	// 라인 클리어 점수
		return level * 10;
	}
	int blockScore() {	// 블록 클리어 점수
		return level * 1;
	}
	int lineBonus() {	//  라인 한 번에 처리 시 보너스 점수 라인 하나에 대한 보너스 점수
		return level * 10;
	}
	void levelUpdate() {	// 라인 수에 따른 레벨 조정
		level = 1+line/5;
	}
	virtual void drawPointSetting(int drawX, int drawY) {
		this->drawX = drawX;
		this->drawY = drawY;
	}
public:
	ScoreManager(ScoreBoard* scoreBoard) : scoreBoard(scoreBoard), level(1), score(0), line(0), block(0) {};
	void draw(int drawX, int drawY) {
		drawPointSetting(drawX, drawY);
		redraw();
	}
	long long getScore() {
		return score;
	}
	void redraw() {
		scoreBoard->draw(drawX, drawY, level, score, line, block);
	}
	void redrawContent() {
		scoreBoard->redrawContent(level, score, line, block);
	}
	void addBlock(int blockNum) {
		block += blockNum;
		score += blockScore() * blockNum;
	}
	void addLine(int lineNum) {
		this->line += lineNum;
		score += lineScore() * lineNum + lineBonus()*(lineNum-1);
		levelUpdate();
	}
	int getLevel() {
		return level;
	}
	~ScoreManager() {
		delete scoreBoard;
	}
};