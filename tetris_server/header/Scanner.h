#pragma once
#include <string>
#include "ColorPrinter.h"
#include "Object.h"
#include "Painter.h"
using namespace std;
class Scanner : public Object{
private:
	string text;
	Printer* printer;
public:
	Scanner(int x, int y, int w, int h, Printer* printer): Object(x, y, w, h), printer(printer) {};
	void draw(int drawX, int drawY) override{
		Object::setDrawPosition(drawX, drawY);
		draw();
	}
	void draw() override {
		printer->printText(x, y, w, h, { text });
	}
	void erase() override {
		Painter({ " " }).rect(x, y, w, h);
	}
	void enter(char c) {
		if (c == 8) {	// backspace�� ��� �� �� ���� ����
			if (!text.empty()) {
				erase();
				text.pop_back();
				draw();
			}
		}
		else {
			if (text.size() < w) { // ���۰� ���� �ʾҴٸ�.
				text.push_back(c);	// �Էµ� ���� �߰�
				draw();
			}
		}

	}
	void emptyOut() {
		text = "";
	}
	string getText() {
		return text;
	}
};