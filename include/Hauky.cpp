#include "Console.hpp"
#include "Hauky.hpp"
#include "Material.hpp"
#include <conio.h>
#include <iostream>
#include <iomanip> //Cai nay de dung std::setw() thoi

void Phongcachthoitrang()
{
	GetUserData();
	GetLanguagePack();
	GetLevelPack();

	GetLogoInfo();
	GetColorPalette();						  //Lay mau
	ChangeColorPallete(UserNowData.Nowtheme); //Doi mau

	DisableResize();

	ShowCursor(false);
	ResizeScreenBuffer(100, 40);
	ResizeConsole(100, 40);

	system("color 01");
}

void PrintMainLayout()
{
	PrintLogo(16, 4, false);

	Gotoxy(2, 38);
	std::cout << std::setw(96) << Language[UserNowData.Nowlanguage].CreditList[4];
	Gotoxy(2, 38);
	std::cout << Language[UserNowData.Nowlanguage].CreditList[3];

	for (int i = 0; i < 5; i++)
	{
		PrintBlock(30, 3, 35, 14 + i * 4, 0);
		Gotoxy(35, 15 + 4 * i);
		std::cout << std::setw(27) << Language[UserNowData.Nowlanguage].MenuList[i];
	}
}

void ChangeMainSelect(short previousmain, short nowmain)
{
	//Hoa den cai cu
	ColorBlock(30, 3, 35, 14 + previousmain * 4, 0x01);
	//Hoa xanh cai moi
	ColorBlock(30, 3, 35, 14 + nowmain * 4, 0x10);
}

void PrintLevelLayout()
{
	DoiMauChu(0x04); //Xam mong mo

	//Lop nen
	for (short i = 0; i < 3; i++)
		for (short j = 0; j < 4; j++)
			PrintBlock(20, 9, 4 + 24 * j, 7 + 11 * i, 4);
	//O vuong cuoi trang
	{
		for (short i = 0; i < 4; i++)
		{
			Gotoxy(13 + 24 * i, 38);
			std::cout << (char)220 << (char)220;
			Gotoxy(13 + 24 * i, 39);
			std::cout << (char)223 << (char)223;
		}
	}
	//Logo
	PrintLogo(62, 2, true);
	//Level, Do kho, diem cao
	DoiMauChu(0x01);
	Gotoxy(4, 2);
	std::cout << Language[UserNowData.Nowlanguage].LevelList[0];
	Gotoxy(4, 3);
	std::cout << Language[UserNowData.Nowlanguage].LevelList[1];
	Gotoxy(4, 4);
	std::cout << Language[UserNowData.Nowlanguage].LevelList[2];
}

void PrintLevelPage(short pagenumber)
{
	//Lop so nen
	for (short i = 0; i < 12; i++)
		PrintLevelNumber(i % 4, i / 4, i + 1 + pagenumber * 12, 4);

	//O vuong cuoi trang xanh
	{
		DoiMauChu(0x01);
		Gotoxy(13 + 24 * pagenumber, 38);
		std::cout << (char)220 << (char)220;
		Gotoxy(13 + 24 * pagenumber, 39);
		std::cout << (char)223 << (char)223;
	}
}

void ChangeLevelSelect(short previouslevel, short nowlevel)
{
	//Vi tri tuong doi cua cu va moi, tinh tu 0 theo bang 3x4
	short Xpre = previouslevel % 4, Ypre = previouslevel / 4;
	short Xnow = nowlevel % 4, Ynow = nowlevel / 4;

	//Neu chuyen trang thi phai in lai ca page moi, khong thi chi can hoa xam level cu
	if (previouslevel / 12 != nowlevel / 12) //Chuyen trang
	{
		//Hoa xam cai nen cu
		PrintBlock(20, 9, 4 + 24 * Xpre, 7 + 11 * (Ypre % 3), 4);
		//Lap page moi
		PrintLevelPage(nowlevel / 12);
		//Hoa xam o vuong cuoi trang cu
		{
			DoiMauChu(0x04);
			Gotoxy(13 + 24 * (previouslevel / 12), 38);
			std::cout << (char)220 << (char)220;
			Gotoxy(13 + 24 * (previouslevel / 12), 39);
			std::cout << (char)223 << (char)223;
		}
	}
	else //Khong chuyen trang
	{
		//Hoa xam level cu
		PrintBlock(20, 9, 4 + Xpre * 24, 7 + (Ypre % 3) * 11, 4);
		PrintLevelNumber(Xpre, Ypre % 3, previouslevel + 1, 4);
	}
	//Hoa xanh level moi
	PrintBlock(20, 9, 4 + Xnow * 24, 7 + (Ynow % 3) * 11, 1);
	PrintLevelNumber(Xnow, Ynow % 3, nowlevel + 1, 1);

	//Thong tin level
	DoiMauChu(0x02);
	Gotoxy(19, 2);
	std::cout << std::setw(5) << nowlevel + 1;
	Gotoxy(19, 3);
	std::cout << "OOOOO";
	Gotoxy(19, 4);
	std::cout << std::setw(5) << UserNowData.HighScore[nowlevel + 1];

	DoiMauChu(0x03);
	Gotoxy(19, 3);
	for (int i = 0; i < Level[nowlevel + 1].Rate; i++)
		std::cout << "O";
}

void PrintPlayLayout(short Levelnumber)
{
	DoiMauChu(0x01);
	Gotoxy(4, 1);
	std::cout << Language[UserNowData.Nowlanguage].LevelList[0] << ": " << Levelnumber << "\n";
	Gotoxy(83, 1);
	std::cout << Language[UserNowData.Nowlanguage].LevelList[2] << ":\n";
	for (short i = 0; i < 100; i++)
		std::cout << (char)95;
	Gotoxy(2 * Level[Levelnumber].Man.X, Level[Levelnumber].Man.Y);
	std::cout << "><";
	Gotoxy(2 * Level[Levelnumber].Des.X, Level[Levelnumber].Des.Y);
	std::cout << "[]";

	DoiMauChu(0x02);
	for (int i = 0; i < Level[Levelnumber].BlockNum; i++)
	{
		Gotoxy(2 * Level[Levelnumber].Block[i].X, Level[Levelnumber].Block[i].Y);
		std::cout << (char)219 << (char)219;
	}

	if (Level[Levelnumber].isHole)
	{
		DoiMauChu(0x03);
		Gotoxy(2 * Level[Levelnumber].Hole[0].X, Level[Levelnumber].Hole[0].Y);
		std::cout << "()";
		Gotoxy(2 * Level[Levelnumber].Hole[1].X, Level[Levelnumber].Hole[1].Y);
		std::cout << "()";
	}
}

//Co thang khong vay ta? Thang xong co di tiep khong ta?
bool Endgame(bool isWin, int Score)
{
	bool out = false; //Muon ngung hay la khong?

	DoiMauChu(0x41);
	PrintBlock(40, 16, 30, 12, 4);
	Gotoxy(30, 14);
	for (int i = 0; i < 40; i++)
		std::cout << (char)95;
	Gotoxy(30, 24);
	for (int i = 0; i < 40; i++)
		std::cout << (char)95;

	if (isWin)
	{
		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[0].length() / 2, 13);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[0];
		Gotoxy(40 - Language[UserNowData.Nowlanguage].PlayList[3].length() / 2, 26);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[3];
		Gotoxy(60 - Language[UserNowData.Nowlanguage].PlayList[2].length() / 2, 26);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[2];

		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[5].length() / 2, 18);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[5];
		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[6].length() / 2, 20);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[6];
		Gotoxy(49, 21);
		std::cout << Score;
	}
	else
	{
		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[1].length() / 2, 13);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[1];
		Gotoxy(40 - Language[UserNowData.Nowlanguage].PlayList[4].length() / 2, 26);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[4];
		Gotoxy(60 - Language[UserNowData.Nowlanguage].PlayList[2].length() / 2, 26);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[2];

		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[7].length() / 2, 18);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[7];
		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[8].length() / 2, 20);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[8];
		Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[9].length() / 2, 21);
		std::cout << Language[UserNowData.Nowlanguage].PlayList[9];
	}

	ColorBlock(20, 3, 30 + 20 * out, 25, 0x14); //Hoa xanh lan dau

	while (true)
	{
		int Key = GetKeyButton();
		if (Key == _ESC_KEY)
			return false;
		else if (Key == _ENTER_KEY || Key == _SPACE_KEY)
			return out;

		else if (Key == _LEFT_KEY || Key == _RIGHT_KEY)
		{
			ColorBlock(20, 3, 30 + 20 * out, 25, 0x41); //Hoa den cai cu
			out = 1 - out;
			ColorBlock(20, 3, 30 + 20 * out, 25, 0x14); //Hoa xanh cai moi
		}
	}
}

COORD MoveMan(COORD pos, int Key, short levelnumber)
{
	//Dieu huong
	COORD Direction;
	if (Key == _UP_KEY)
		Direction = {0, -1}; //x, y - 1
	else if (Key == _DOWN_KEY)
		Direction = {0, 1}; //x, y + 1
	else if (Key == _LEFT_KEY)
		Direction = {-1, 0}; //x - 1, y
	else if (Key == _RIGHT_KEY)
		Direction = {1, 0}; //x + 1, y

	//Bay den khi nao dam nhau thi thoi;
	while (true)
	{
		COORD Newpos = {(short)(pos.X + Direction.X), (short)(pos.Y + Direction.Y)};

		if (Newpos.X < 0 || Newpos.X > 49 || Newpos.Y < 3 || Newpos.Y > 39) //Ra ngoai chuong ga
		{
			return {0, 0};
		}
		else if (StatusLevel[Newpos.Y][Newpos.X] == 1) //Cuc gach
		{
			if (!Level[levelnumber].isSpecial) //Man binh thuong
				return pos;
			else
			{
				StatusLevel[Newpos.Y][Newpos.X] = 0; //Bien thanh binh thuong

				Gotoxy(2 * Newpos.X, Newpos.Y);
				std::cout << "  ";

				return pos;
			}
		}

		else if (StatusLevel[Newpos.Y][Newpos.X] == 2) //Lo hong
		{
			if (Level[levelnumber].Hole[0].X == Newpos.X && Level[levelnumber].Hole[0].Y == Newpos.Y)
			{
				Newpos.X = Level[levelnumber].Hole[1].X + Direction.X;
				Newpos.Y = Level[levelnumber].Hole[1].Y + Direction.Y;
			}
			else
			{
				Newpos.X = Level[levelnumber].Hole[0].X + Direction.X;
				Newpos.Y = Level[levelnumber].Hole[0].Y + Direction.Y;
			}

			Gotoxy(2 * pos.X, pos.Y);
			std::cout << "  ";
			pos = Newpos;
			Gotoxy(2 * pos.X, pos.Y);
			std::cout << "><";
		}
		else if (StatusLevel[Newpos.Y][Newpos.X] == 3) //Dich
		{
			Gotoxy(2 * pos.X, pos.Y);
			std::cout << "  ";
			return Newpos;
		}
		else //Khong gian
		{
			Gotoxy(2 * pos.X, pos.Y);
			std::cout << "  ";

			pos = Newpos;

			Gotoxy(2 * pos.X, pos.Y);
			std::cout << "><";
		}
		Sleep(20);
		//De phong an linh tinh trong luc choi
		if (_kbhit())
			GetKeyButton();
	}
}

void PrintOptionLayout(bool isFirst)
{
	if (isFirst) //Lan dau ha
	{
		//Cat dat
		DoiMauChu(0x03);
		Gotoxy(6, 3);
		for (int i = 0; i < 40; i++)
			std::cout << (char)95;
		Gotoxy(6, 9);
		for (int i = 0; i < 40; i++)
			std::cout << (char)95;
		//Phong cach
		Gotoxy(18, 5);
		std::cout << "<";
		Gotoxy(41, 5);
		std::cout << ">";
		//Bang mau, vien
		{
			for (int i = 0; i < 22; i++)
			{
				Gotoxy(19 + i, 6);
				std::cout << (char)196;
				Gotoxy(19 + i, 8);
				std::cout << (char)196;
			}
			Gotoxy(19, 6);
			std::cout << (char)218;
			Gotoxy(19, 7);
			std::cout << (char)124;
			Gotoxy(19, 8);
			std::cout << (char)192;
			Gotoxy(40, 6);
			std::cout << (char)191;
			Gotoxy(40, 7);
			std::cout << (char)124;
			Gotoxy(40, 8);
			std::cout << (char)217;

			for (int i = 0; i < 4; i++)
				PrintBlock(5, 1, 20 + 5 * i, 7, i + 1);
		}
		//Ngon ngu
		Gotoxy(18, 11);
		std::cout << "<";
		Gotoxy(41, 11);
		std::cout << ">";
	}

	//Co moi noi cu
	DoiMauChu(0x03);
	Gotoxy(6, 2);
	std::cout << std::setw(20) << " ";
	Gotoxy(6, 2);
	std::cout << Language[UserNowData.Nowlanguage].OptionList[0];
	Gotoxy(6, 15);
	std::cout << std::setw(20) << " ";
	Gotoxy(6, 15);
	std::cout << Language[UserNowData.Nowlanguage].OptionList[4];

	DoiMauChu(0x04);

	//Phong cach
	Gotoxy(6, 5);
	std::cout << std::setw(12) << " "; //Cach cach
	Gotoxy(6, 5);
	std::cout << Language[UserNowData.Nowlanguage].OptionList[1];
	//Ngon ngu
	Gotoxy(6, 11);
	std::cout << std::setw(12) << " "; //Cach cach
	Gotoxy(6, 11);
	std::cout << Language[UserNowData.Nowlanguage].OptionList[2];

	Gotoxy(20, 11);
	std::cout << std::setw(20) << " "; //Cach cach
	Gotoxy(20, 11);					   //Tieng Viet, English
	std::cout << std::setw(20 - (20 - Language[UserNowData.Nowlanguage].OptionList[3].length()) / 2)
			  << Language[UserNowData.Nowlanguage].OptionList[3];

	Gotoxy(20, 5);
	std::cout << std::setw(20) << " "; //Cach cach
	Gotoxy(20, 5);					   //Ten phong cach
	std::cout << std::setw(20 - (20 - MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage].length()) / 2)
			  << MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage]; //Can giua

	DoiMauChu(0x01); //Tra lai mau cho em
}

bool PrintTextByRaw(short margin)
{
	short maxWritesize = 100 - 2 * margin;
	int count = GetTextRaw();
	short nowX = 0; //Vi tri cua con chuot hien tai, tinh theo vung viet. (0-maxWritesize)
	short nowY = 0; //Vi tri cua con chuot hien tai, tinh theo vung viet. (0-34)

	for (int j = 0; j < margin; j++) //Can le lan dau
		std::cout << " ";
	for (int i = 0; i < count; i++)
	{
		if (TextRawColor[i] == 0) //Neu bang 0 thi xuong dong, qua ro rang roi
		{
			//Qua kho thi dung lai
			if (nowY + 2 >= 34)
			{
				while (true)
				{
					int Key = GetKeyButton();

					if (Key == _ESC_KEY)
						return false;

					else if (Key == _TAB_KEY || Key == _SPACE_KEY || Key == _ENTER_KEY)
					{
						PrintBlock(maxWritesize, 92, margin, 4, 0);
						nowX = nowY = 0;

						Gotoxy(0, 4);
						for (int j = 0; j < margin; j++) //Can le lan sau
							std::cout << " ";

						break;
					}
				}
			}
			else //Khong thi van cu in nhu thuong
			{
				std::cout << std::endl
						  << std::endl;
				for (int j = 0; j < margin; j++) //Can le
					std::cout << " ";
				nowX = 0;
				nowY += 2;
			}
		}
		else
		{
			DoiMauChu(TextRawColor[i]);

			int printedchar = 0;						 //So chu cai da in.
			int TextRawLength = TextRaw[i].length() - 1; //So chu can phai in

			while (nowX + TextRawLength - printedchar >= maxWritesize) //Neu so chu vuot qua muc quy dinh thi sao?
			{
				short writelength = maxWritesize - nowX; //So chu se phai ghi tiep theo
				for (int j = printedchar; j < printedchar + writelength; j++)
					std::cout << TextRaw[i][j + 1];

				if (nowY + 1 >= 34) //Neu qua kho thi sao?
				{
					while (true)
					{
						int Key = GetKeyButton();

						if (Key == _ESC_KEY)
							return false;

						else if (Key == _TAB_KEY || Key == _SPACE_KEY || Key == _ENTER_KEY)
						{
							PrintBlock(maxWritesize, 92, margin, 4, 0);
							nowY = 0;

							Gotoxy(0, 4);
							for (int j = 0; j < margin; j++) //Can le lan sau
								std::cout << " ";

							break;
						}
					}
				}

				else
				{
					std::cout << std::endl; //Xuong dong la ro
					for (int j = 0; j < margin; j++)
						std::cout << " ";

					nowY++;
				}

				printedchar += writelength;
				nowX = 0;
			}

			if (printedchar == TextRawLength) //Neu da in du roi thi thoi khong in nua
				continue;

			//Neu khong du ta moi phai lam tiep
			for (int j = printedchar; j < TextRawLength; j++) //In phan con lai
				std::cout << TextRaw[i][j + 1];
			nowX = (nowX + TextRawLength + 1 - printedchar);
			std::cout << " "; //Khoang trang cuoi tu.
		}
	}

	return true;
}