#include <windows.h>
#include "CoordinateSystem.h"

void CoordinateSystem::move(int x, int y) {
	COORD pos = { x_scale * x, y_scale * y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
pair<int, int> CoordinateSystem::getCoordinate() {
	CONSOLE_SCREEN_BUFFER_INFO a;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	return make_pair(a.dwCursorPosition.X, a.dwCursorPosition.Y);
};