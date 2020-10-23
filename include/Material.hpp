#ifndef MATERIAL_H
#define MATERIAL_H

#include <windows.h>
#include <iostream>

struct StyleInfo
{
	std::string StyleName[2];
	COLORREF BackgroundColor;
	COLORREF MainTextColor;
	COLORREF SecondTextColor;
	COLORREF ThirdTextColor;
	COLORREF DisableColor;
};

struct LanguagePack
{
	std::string Label;
	std::string MenuList[5];
	std::string LevelList[3];
	std::string PlayList[10];
	std::string StoryList[2];
	std::string OptionList[5];
	std::string CreditList[20];
};

struct LevelPack
{
	short Rate;
	short BlockNum;
	bool isHole;
	bool isSpecial;

	COORD Man;
	COORD Des;

	COORD Block[200];
	COORD Hole[2];
	short SpaceStatus[40][100];
};

struct UserData
{
	short Nowtheme;
	short Nowlanguage;
	std::string EncryptScore;
	int HighScore[50];
};

//Ma tran level hien tai
extern short StatusLevel[40][50];

//Thong tin ngon ngu
extern LanguagePack Language[2];
//Thong tin man choi
extern LevelPack Level[50];
//Thong tin tac gia
extern std::string AuthorList[12];
//Thong tin nguoi choi
extern UserData UserNowData;
//Thong tin bang mau
extern StyleInfo MyColorPalette[10];
//Thong tin cua in so
extern char NumberInfo[6][32];
//Thong tin cua logo
extern char LogoInfo[8][40];
extern WORD LogoInfoColor[5][35];

//Nhap thong tin cho man choi
void GetLevelPack();
//Copy thong tin man choi
void CopyStatusLevel(short levelnumber);
//Nhap thong tin ngon ngu
void GetLanguagePack();
//Nhap thong tin nguoi choi
void GetUserData();
//Ghi thong tin nguoi choi
void SetUserData();

//Nhap bang mau cho game
void GetColorPalette();

//Nhap bang mau cho logo
void GetLogoInfo();

//Thong tin cho van ban loai tho
extern std::string TextRaw[500];
extern short TextRawColor[500];

//Nhap tep van ban loai tho
short GetTextRaw();

#endif