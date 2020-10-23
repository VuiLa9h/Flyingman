#ifndef _HAUKY_H
#define _HAUKY_H

#include <windows.h>
//Thay doi kich co va vo hieu hoa viec sua doi lung tung
void Phongcachthoitrang();

//In lop nen cho trang chinh
void PrintMainLayout();
//Thay doi phan cai dat
void ChangeMainSelect(short previousmain, short nowmain);

//In lop nen cho danh sach level
void PrintLevelLayout();
//In so, o vuong cuoi trang, level
void PrintLevelPage(short pagenumber);
//Thay doi vi tri 2 level dang duoc chon
void ChangeLevelSelect(short previouslevel, short nowlevel);
//In lop nen, cac cuc gach, lo hong, ...
void PrintPlayLayout(short Levelnumber);
//Di chuyen sieu nhan
COORD MoveMan(COORD pos, int Key, short levelnumber);
//Co thang khong vay ta? Thang xong co di tiep khong ta?
bool Endgame(bool isWin, int Score);

//In lop nen cho trang cai dat, true la lan dau, false la in de
void PrintOptionLayout(bool isFirst);
//In van ban theo dinh dang da quy uoc trong docs
bool PrintTextByRaw(short margin);
#endif