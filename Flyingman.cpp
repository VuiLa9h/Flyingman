#include <conio.h>
#include <iostream>
#include <iomanip> //setw
#include <fstream>
#include <windows.h>
#include "Hauky.hpp"
#include "Console.hpp"
#include "Material.hpp"

#define Xoamanhinh   \
	DoiMauChu(0x01); \
	system("cls");

using namespace std;

void WelcomePage()
{
	Phongcachthoitrang();

	Xoamanhinh;
	PrintLogo(16, 16, false);
	Sleep(1000);
}

int MainPage()
{
	Xoamanhinh;
	short premain = 0, nowmain = 0;

	PrintMainLayout();
	ChangeMainSelect(0, 0);

	//Duong doi bat tan
	while (true)
	{
		int Key = GetKeyButton();

		if (Key == _DOWN_KEY)
		{
			premain = nowmain;
			nowmain = (nowmain + 1) % 5;

			ChangeMainSelect(premain, nowmain);
		}
		else if (Key == _UP_KEY)
		{
			premain = nowmain;
			nowmain = (nowmain + 4) % 5;

			ChangeMainSelect(premain, nowmain);
		}

		else if (Key == _ENTER_KEY || Key == _SPACE_KEY)
			return nowmain;

		Sleep(50); //Ngu mot chut cho khoe nhe
	}
}

// >= 0 thi di tiep, -1 thi ve menu chinh
int LevelPage()
{
	Xoamanhinh;
	PrintLevelLayout();
	PrintLevelPage(0);
	ChangeLevelSelect(0, 0);

	short level = 0;

	while (true)
	{
		int Key = GetKeyButton();

		if (Key == _ENTER_KEY || Key == _SPACE_KEY)
			return level + 1;
		else if (Key == _ESC_KEY)
			return -1;

		//Neu phim phai va khong phai bien phai nhat
		else if (Key == _RIGHT_KEY && (level != 39 && level != 40 && level != 47))
		{
			short prelevel = level;

			if (level % 4 == 3) //Level canh phai cua trang, qua ngau
				level += 9;		//Chuyen trang
			else
				level++;

			ChangeLevelSelect(prelevel, level);
		}
		//Neu phim trai va khong phai bien trai nhat
		else if (Key == _LEFT_KEY && (level != 0 && level != 4 && level != 8))
		{
			short prelevel = level;

			if (level % 4 == 0) //Level canh trai cua trang, qua ngau
				level -= 9;		//Chuyen trang
			else
				level--;

			ChangeLevelSelect(prelevel, level);
		}
		//Neu phim xuong va khong phai duoi cung
		else if (Key == _DOWN_KEY && level <= 43)
		{
			level += 4; //Chuyen dong
			ChangeLevelSelect(level - 4, level);
		}
		//Neu phim len va khong phai tren cung
		else if (Key == _UP_KEY && level >= 4)
		{
			level -= 4; //Chuyen dong
			ChangeLevelSelect(level + 4, level);
		}
		//Neu la phim TAB (Chuyen trang)
		else if (Key == _TAB_KEY)
		{
			short prelevel = level;
			level = (level + 12) % 48;

			ChangeLevelSelect(prelevel, level);
		}

		Sleep(50); //Ngu mot chut cho khoe nhe
	}
}

// >= 0 thi di tiep, -1 thi ve menu chinh
int PlayLevel(int levelnumber)
{
	Xoamanhinh;

	CopyStatusLevel(levelnumber);
	PrintPlayLayout(levelnumber);

	DoiMauChu(0x01);
	COORD Mannow = {Level[levelnumber].Man.X, Level[levelnumber].Man.Y};
	int Score = 0;

	while (true)
	{
		int Key = GetKeyButton();
		Score++;

		if (Score == 1000) //Thua luon
		{
			bool out = Endgame(false, Score);
			if (out)
				return -1;
			else
				return levelnumber;
		}

		if (Key == _ESC_KEY)
			return -1;
		else if (Key == _UP_KEY || Key == _DOWN_KEY || Key == _LEFT_KEY || Key == _RIGHT_KEY)
		{
			COORD NewMannow = MoveMan(Mannow, Key, levelnumber);
			if (NewMannow.X == Mannow.X && NewMannow.Y == Mannow.Y)
				Score--;

			else
			{
				Mannow = NewMannow;
				Gotoxy(93, 1);
				cout << setw(3) << Score;
			}

			if (Mannow.X == 0 && Mannow.Y == 0) //Ra ngoai chuong ga
			{
				bool out = Endgame(false, Score);
				if (out)
					return -1;
				else
					return levelnumber;
			}

			else if (Mannow.X == Level[levelnumber].Des.X && Mannow.Y == Level[levelnumber].Des.Y) //Ve dich
			{
				if (Score < UserNowData.HighScore[levelnumber] || UserNowData.HighScore[levelnumber] == 0)
				{
					UserNowData.HighScore[levelnumber] = Score;
					SetUserData();
				}

				bool out = Endgame(true, Score);
				if (out || levelnumber == 48)
					return -1;
				else
					return levelnumber + 1;
			}
		}
	}
}

void StoryPage()
{
	Xoamanhinh;
	Gotoxy(6, 1);
	cout << setw(88) << Language[UserNowData.Nowlanguage].StoryList[1];
	Gotoxy(6, 1);
	cout << Language[UserNowData.Nowlanguage].StoryList[0] << endl;
	for (int i = 0; i < 100; i++)
		cout << (char)95;

	Gotoxy(0, 4);
	if (PrintTextByRaw(6) == false)
		return;

	while (true)
	{
		int Key = GetKeyButton();
		if (Key == _ESC_KEY || Key == _TAB_KEY || Key == _SPACE_KEY || Key == _ENTER_KEY)
			return;
	}
}

void OptionPage()
{
	Xoamanhinh;

	bool isThemenow = true; //Vi tri hien tai, co phai dang o theme khong?

	PrintOptionLayout(true);

	ChangeOptionNowcursor(isThemenow);

	while (true)
	{
		int Key = GetKeyButton();
		if (Key == _UP_KEY || Key == _DOWN_KEY)
		{
			isThemenow = 1 - isThemenow;
			ChangeOptionNowcursor(isThemenow);
		}

		else if (Key == _RIGHT_KEY && isThemenow)
		{
			UserNowData.Nowtheme = (UserNowData.Nowtheme + 1) % 6;
			ChangeColorPallete(UserNowData.Nowtheme);
		}

		else if (Key == _LEFT_KEY && isThemenow)
		{
			UserNowData.Nowtheme = (UserNowData.Nowtheme + 5) % 6;
			ChangeColorPallete(UserNowData.Nowtheme);
		}

		else if ((Key == _LEFT_KEY || Key == _RIGHT_KEY) && !isThemenow) //Neu thay doi ngon ngu?
		{
			UserNowData.Nowlanguage = 1 - UserNowData.Nowlanguage;
			SetUserData(); //Luu thong tin

			PrintOptionLayout(false);
			ChangeOptionNowcursor(isThemenow);
		}

		else if (Key == _ESC_KEY)
		{
			SetUserData();
			return;
		}

		Sleep(50); //Ngu mot chut cho khoe nhe
	}
}

void CreditPage()
{
	Xoamanhinh;

	PrintPlayLayout(0);
	PrintBlock(100, 3, 0, 0, 0);
	//Gach gach
	DoiMauChu(0x03);
	Gotoxy(6, 2);
	cout << Language[UserNowData.Nowlanguage].CreditList[0];
	Gotoxy(6, 3);
	for (int i = 0; i < 52; i++)
		cout << (char)95;
	Gotoxy(6, 4 + 2 * 12);
	for (int i = 0; i < 52; i++)
		cout << (char)95;
	Gotoxy(6, 4 + 2 * 15);
	for (int i = 0; i < 52; i++)
		cout << (char)95;

	//Tac con nha ba gia
	DoiMauChu(0x02);
	for (int i = 0; i < 12; i++)
	{
		Gotoxy(6, 5 + 2 * i);
		cout << setw(52) << AuthorList[i];
	}

	//Thong con nha ba tin
	DoiMauChu(0x01);
	for (int i = 0; i < 12; i++)
	{
		Gotoxy(6, 5 + 2 * i);
		cout << Language[UserNowData.Nowlanguage].CreditList[i + 7];
	}
	for (int i = 1; i <= 4; i++) //List copyright
	{
		Gotoxy(6, 29 + i);
		cout << Language[UserNowData.Nowlanguage].CreditList[i];
	}
	for (int i = 5; i <= 6; i++) //List key
	{
		Gotoxy(6, 31 + i);
		cout << Language[UserNowData.Nowlanguage].CreditList[i];
	}

	while (true)
	{
		int Key = GetKeyButton();

		if (Key == _ENTER_KEY || Key == _SPACE_KEY)
		{
			system("start https://www.youtube.com/vtysvt");
			exit(0);
		}
		else if (Key == _ESC_KEY)
			return;
		else
			continue;
	}
}

void ExitPage()
{
	exit(0);
}

int main()
{
	WelcomePage();
	while (true)
	{
		int nowgoto = MainPage();

		//Level
		if (nowgoto == 0)
		{
			int levelgo = LevelPage();

			while (levelgo != -1)
				levelgo = PlayLevel(levelgo);
		}

		//Story
		else if (nowgoto == 1)
			StoryPage();
		//Option
		else if (nowgoto == 2)
			OptionPage();
		//Credit
		else if (nowgoto == 3)
			CreditPage();
		else
			ExitPage();
	}
}