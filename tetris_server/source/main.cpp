#pragma warning(disable:4996)
#define _HAS_STD_BYTE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <conio.h>
#include <time.h>
#include <vector>
#include <string>
#include "server.h"
#include "error.h"
#include "stringList.h"
#include "user.h"
#include "utill.h"
#include "string+.h"
#include "file.h"
#include "userManager.h"
#include "mainScreen.h"
#include "scoreManager.h"
#include "math+.h"
#include <windows.h>
#include "timer.h"
#include "tetris.h"
#include "graphic.h"
#include "block.h"
#include "tetris.h"
#include "Button.h"
#include "ColorPainter.h"
#include "ColorPrinter.h"
#include "system.h"
#include "ButtonManager.h"
#include "string+.h"
#include <iostream>
#include "Canvas.h"
#include "Scene.h"
#include "bean.h"
using namespace std;
void responseHandler(char* request, char* response) {
	strcpy(response, request);
	return;
}
GraphicManager* gm;


int main(int argc, char* argv[]) {
	Consol::changeScreenSize(WIDTH, HEIGHT);
	Consol::setCursorFlag(false);
	//Test();
	//serverRun(5000, responseHandler);
	string result1 = ModeSelectScene()->start();
	string result2 = SingleModeMeneSelectScene()->start();
}

