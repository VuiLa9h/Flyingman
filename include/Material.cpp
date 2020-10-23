#include "Material.hpp"
#include <iostream>
#include <fstream>
#include <windows.h>

#define materialpath "../Material/"

LanguagePack Language[2];

void GetLanguagePack()
{
	Language[0].Label = "Vi";

	Language[0].MenuList[0] = "    BAT DAU TRO CHOI    ";
	Language[0].MenuList[1] = " CAU CHUYEN & HUONG DAN ";
	Language[0].MenuList[2] = " PHONG CACH THOI THUONG ";
	Language[0].MenuList[3] = "     GA KEO TAC GIA     ";
	Language[0].MenuList[4] = "    VANG RA CHUONG GA   ";

	Language[0].LevelList[0] = "Man choi";
	Language[0].LevelList[1] = "Do kho";
	Language[0].LevelList[2] = "Diem cao";

	Language[0].PlayList[0] = "THANG ROI, GIOI QUA DI :O";
	Language[0].PlayList[1] = "THUA MAT ROI :((";
	Language[0].PlayList[2] = "VE MENU CHINH";
	Language[0].PlayList[3] = "CHOI TIEP";
	Language[0].PlayList[4] = "CHOI LAI";
	Language[0].PlayList[5] = "Xin chuc mung, Chau Bui!";
	Language[0].PlayList[6] = "Diem so cua ban la";
	Language[0].PlayList[7] = "Con ong ba choi ngu nhu bo!";
	Language[0].PlayList[8] = "Toi that khong the hieu noi";
	Language[0].PlayList[9] = "ong ba co biet day con khong nua?";

	Language[0].StoryList[0] = "Huong dan su dung";
	Language[0].StoryList[1] = "An TAB/SPACE/ENTER de chuyen trang";

	Language[0].OptionList[0] = "Cai dat";
	Language[0].OptionList[1] = "Phong cach";
	Language[0].OptionList[2] = "Ngon ngu";
	Language[0].OptionList[3] = "Tieng Viet";
	Language[0].OptionList[4] = "An ESC de thoat";

	Language[0].CreditList[0] = "Tac gia & Tac pham";
	Language[0].CreditList[1] = "Hiep sy khong gian";
	Language[0].CreditList[2] = "Version: 1.0.0";
	Language[0].CreditList[3] = "(C) 2001 - 2020, Vtysvt Inc";
	Language[0].CreditList[4] = "Made by CrazyrabVn & Light Bro Animation";
	Language[0].CreditList[5] = "An ESC de thoat";
	Language[0].CreditList[6] = "An Enter de ga dam nhau voi tac gia";

	Language[0].CreditList[7] = "Chiu trach nhiem san xuat";
	Language[0].CreditList[8] = "Khung chuong trinh";
	Language[0].CreditList[9] = "Cot truyen";
	Language[0].CreditList[10] = "Thiet ke man choi";
	Language[0].CreditList[11] = "Giao dien nguoi dung";
	Language[0].CreditList[12] = "Thuat toan";
	Language[0].CreditList[13] = "Ky xao, hieu ung";
	Language[0].CreditList[14] = "Hau ky";
	Language[0].CreditList[15] = "Dich thuat";
	Language[0].CreditList[16] = "Huong dan su dung";
	Language[0].CreditList[17] = "Choi thu va loi sml";
	Language[0].CreditList[18] = "Quang cao";

	/**/ /**/ /**/ /**/

	Language[1].Label = "En";

	Language[1].MenuList[0] = "       START GAME       ";
	Language[1].MenuList[1] = "    STORY & GUIDANCE    ";
	Language[1].MenuList[2] = "    LANGUAGE & STYLE    ";
	Language[1].MenuList[3] = "         CREDIT         ";
	Language[1].MenuList[4] = "        END GAME        ";

	Language[1].LevelList[0] = "Level";
	Language[1].LevelList[1] = "Difficult";
	Language[1].LevelList[2] = "Score";

	Language[1].PlayList[0] = "YOU ARE WINNER!";
	Language[1].PlayList[1] = "YOU ARE LOSER!";
	Language[1].PlayList[2] = "GO TO MENU";
	Language[1].PlayList[3] = "NEXT LEVEL";
	Language[1].PlayList[4] = "REPLAY";
	Language[1].PlayList[5] = "Congratulation, Chau Bui!";
	Language[1].PlayList[6] = "Your score is";
	Language[1].PlayList[7] = "Con ong ba choi ngu nhu bo!";
	Language[1].PlayList[8] = "Toi that khong the hieu noi";
	Language[1].PlayList[9] = "ong ba co biet day con khong nua?";

	Language[1].StoryList[0] = "Story and guidance";
	Language[1].StoryList[1] = "Press TAB/SPACE/ENTER to go to next page";

	Language[1].OptionList[0] = "Setting";
	Language[1].OptionList[1] = "Theme";
	Language[1].OptionList[2] = "Language";
	Language[1].OptionList[3] = "English";
	Language[1].OptionList[4] = "Press ESC to exit";

	Language[1].CreditList[0] = "Credit";
	Language[1].CreditList[1] = "Flying Man";
	Language[1].CreditList[2] = "Version: 1.0.0";
	Language[1].CreditList[3] = "(C) 2001 - 2020, Vtysvt Inc";
	Language[1].CreditList[4] = "Made by CrazyrabVn & Light Bro Animation";
	Language[1].CreditList[5] = "Press ESC to exit";
	Language[1].CreditList[6] = "Press Enter to go to author's page";

	Language[1].CreditList[7] = "Producer";
	Language[1].CreditList[8] = "Program bone";
	Language[1].CreditList[9] = "Story";
	Language[1].CreditList[10] = "Level design";
	Language[1].CreditList[11] = "UI / UX";
	Language[1].CreditList[12] = "Algorithm";
	Language[1].CreditList[13] = "Visual FX";
	Language[1].CreditList[14] = "Editor";
	Language[1].CreditList[15] = "Translator";
	Language[1].CreditList[16] = "Write documents";
	Language[1].CreditList[17] = "Tester";
	Language[1].CreditList[18] = "Marketing";
}

short StatusLevel[40][50];
LevelPack Level[50];

void GetLevelPack()
{
	std::string nowpath = materialpath + (std::string) "Level.dat";

	std::fstream data;
	data.open(nowpath, std::ios_base::in);
	for (short i = 0; i < 49; i++)
	{
		//Tao moi mang trang thai
		for (short _i = 0; _i < 40; _i++)
			for (short _j = 0; _j < 100; _j++)
				Level[i].SpaceStatus[_i][_j] = 0;

		data >> Level[i].Rate;
		data >> Level[i].BlockNum;
		data >> Level[i].isHole;
		data >> Level[i].isSpecial;

		data >> Level[i].Man.X >> Level[i].Man.Y;
		data >> Level[i].Des.X >> Level[i].Des.Y;
		Level[i].SpaceStatus[Level[i].Des.Y][Level[i].Des.X] = 3;

		for (int j = 0; j < Level[i].BlockNum; j++)
		{
			data >> Level[i].Block[j].X >> Level[i].Block[j].Y;
			Level[i].SpaceStatus[Level[i].Block[j].Y][Level[i].Block[j].X] = 1;
		}

		if (Level[i].isHole)
		{
			data >> Level[i].Hole[0].X >> Level[i].Hole[0].Y;
			data >> Level[i].Hole[1].X >> Level[i].Hole[1].Y;

			Level[i].SpaceStatus[Level[i].Hole[0].Y][Level[i].Hole[0].X] = 2;
			Level[i].SpaceStatus[Level[i].Hole[1].Y][Level[i].Hole[1].X] = 2;
		}
	}
	data.close();
}

void CopyStatusLevel(short levelnumber)
{
	for (short i = 0; i < 40; i++)
		for (short j = 0; j < 50; j++)
			StatusLevel[i][j] = Level[levelnumber].SpaceStatus[i][j];
}

std::string AuthorList[12] = {
	"Vtysvt",
	"Giang Van Minh",
	"Doremon Viet Nam",
	"Light Bro Animation",
	"Chau Bui",
	"Nguyen Minh Long",
	"Light Bro Animation",
	"Le Nguyen Duong",
	"Pham Hanoi",
	"Chau Bui",
	"Man Chin Rung, Pham Hanoi",
	"Crazyrabvn",
};

UserData UserNowData;
void GetUserData()
{
	std::string nowpath = materialpath + (std::string) "User.dat";
	std::string Garbage; //Thung rac thoi, khong can quan tam

	std::fstream data;
	data.open(nowpath, std::ios_base::in);
	while (!data.eof())
	{
		data >> UserNowData.Nowtheme;
		data >> UserNowData.Nowlanguage;
		std::getline(data, Garbage);
		std::getline(data, UserNowData.EncryptScore);
	}
	data.close();

	//Nhap diem
	for (int i = 0; i < 49; i++)
	{
		UserNowData.HighScore[i] = (UserNowData.EncryptScore[3 * i] - 'a') * 26 * 26;
		UserNowData.HighScore[i] += (UserNowData.EncryptScore[3 * i + 1] - 'a') * 26;
		UserNowData.HighScore[i] += (UserNowData.EncryptScore[3 * i + 2] - 'a');
	}
}

void SetUserData()
{
	std::string nowpath = materialpath + (std::string) "User.dat";

	std::fstream data;
	data.open(nowpath, std::ios_base::out | std::ios_base::trunc); //Ghi de
	data << UserNowData.Nowtheme << " " << UserNowData.Nowlanguage << std::endl;
	for (int i = 0; i < 49; i++)
	{
		char c3 = UserNowData.HighScore[i] % 26 + 'a';
		char c2 = (UserNowData.HighScore[i] / 26) % 26 + 'a';
		char c1 = (UserNowData.HighScore[i] / 26 / 26) % 26 + 'a';
		data << c1 << c2 << c3;
	}
	data.close();
}

StyleInfo MyColorPalette[10];

void GetColorPalette()
{
	std::string nowpath = materialpath + (std::string) "Theme.dat";
	short count = 0;
	short R, G, B;
	std::string Garbage; //Thung rac thoi, khong can quan tam.

	std::ifstream theme(nowpath);
	while (!theme.eof())
	{
		std::getline(theme, Garbage); //Tai sao lai co dong nay? Hay doc (*)

		std::getline(theme, MyColorPalette[count].StyleName[0]);
		std::getline(theme, MyColorPalette[count].StyleName[1]);

		theme >> R >> G >> B;
		MyColorPalette[count].BackgroundColor = RGB(R, G, B);
		theme >> R >> G >> B;
		MyColorPalette[count].MainTextColor = RGB(R, G, B);
		theme >> R >> G >> B;
		MyColorPalette[count].SecondTextColor = RGB(R, G, B);
		theme >> R >> G >> B;
		MyColorPalette[count].ThirdTextColor = RGB(R, G, B);
		theme >> R >> G >> B;
		MyColorPalette[count].DisableColor = RGB(R, G, B);

		count++;
	}
	theme.close();
}

void GetLogoInfo()
{
	//Nhap mau cho logo be
	for (short i = 0; i < 4; i++)
	{
		for (short j = 0; j < 34; j++)
		{
			//Neu la ' ' thi ra 0, con lai ra chinh no
			short backgroundcolor = 0 * (LogoInfo[2 * i][j] == ' ') + (LogoInfo[2 * i][j] != ' ') * (LogoInfo[2 * i][j] - '0' + 12);
			short foregroundcolor = 0 * (LogoInfo[2 * i + 1][j] == ' ') + (LogoInfo[2 * i + 1][j] != ' ') * (LogoInfo[2 * i + 1][j] - '0' + 12);
			LogoInfoColor[i][j] = 16 * backgroundcolor + foregroundcolor;
		}
	}
}

//Thong tin cho van ban loai tho
std::string TextRaw[500];
short TextRawColor[500];
//Nhap van ban
short GetTextRaw()
{
	std::string nowpath = materialpath + (std::string) "Story" + Language[UserNowData.Nowlanguage].Label + (std::string) ".dat";
	int count = 0;

	std::ifstream textraw(nowpath);
	while (!textraw.eof())
	{
		textraw >> TextRawColor[count];
		std::getline(textraw, TextRaw[count]);
		count++;
	}
	textraw.close();

	return count;
}

char NumberInfo[6][32] = {
//	&000111222333444555666777888999
	"111 1 1111111  111111111111111",
	"1 111   1  11 11  1    11 11 1",
	"1 1 1 111 11111111111 11111111",
	"1 1 1 1    1  1  11 1  11 1  1",
	"111111111111  1111111  1111111",
	"                              ",
};

char LogoInfo[8][40] = {

	"111 2 3333333333333  1   1 3333333",
	"1   2                11 11        ",
	"11  2 2   2  22 22   1 1 1  2   22",
	"1   2 2 2 2 2 2 2 2  1   1 222 2 2",
	"1   2 222 2 2 2 222  1   1 2 2 2 2",
	"        2         2  1            ",
	"222222222 222222222  1111111111111",
	"                                  ",
};
WORD LogoInfoColor[5][35];

/*
Ham getline() doc du lieu den khi gap dau xuong dong thi thoi.
Tu cuoi cua lan lap truoc (B for DisableColor), con tro van dang mac ket o dong DisableColor.
Do do ta phai dung mot bien Garbage de vut dau \0 thua di. Roi sau do moi nhap tiep dong NameVi.
*/