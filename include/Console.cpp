#include <windows.h>
#include <conio.h>
#include <iomanip> //setw
#include "Console.hpp"
#include "Material.hpp"

HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

//For disable
HWND hConsole;
MENUITEMINFO mii;

void ResizeConsole(short width, short height)
{
	SMALL_RECT windowSize = {0, 0, short(width - 1), short(height - 1)};
	SetConsoleWindowInfo(hConsoleOutput, true, &windowSize);
}

void ResizeScreenBuffer(short width, short height)
{
	COORD bufferSize = {width, height};
	SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
}

void Gotoxy(short x, short y)
{
	COORD Cursor_an_Pos = {(short)x, (short)y};
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void ShowCursor(bool CursorVisibility)
{
	CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
	SetConsoleCursorInfo(hConsoleOutput, &cursor);
}

int GetKeyButton()
{
	int c = _getch();

	if (c == 0xE0) //Khi nhap phim mui ten, no se tra ve 2 gia tri. Dau tien la 0xE0, sau do moi den mui ten
	{
		c = _getch();
		return c;
	}

	if (c == 0) //Day phim f1, f2...
	{
		c = _getch();
		return _OTHER_KEY;
	}

	if ((c == _ESC_KEY) || (c == _ENTER_KEY) || (c == _SPACE_KEY) || (c == _TAB_KEY))
		return c;

	return _OTHER_KEY;
}

void DisableResize()
{
	SetConsoleTitle(TEXT("Flying Man"));
	Sleep(50); //Let the window to update the title!

	hConsole = FindWindow(NULL, TEXT("Flying Man")); //Find this console.
	//Neukhong co lenh sleep thi khong the tim duoc cua so nay

	HMENU hMenu = GetSystemMenu((HWND)hConsole, FALSE);

	mii.fState = MFS_GRAYED;
	EnableMenuItem(hMenu, 4, MF_DISABLED);
	SetMenuItemInfo(hMenu, 4, MF_BYPOSITION, &mii);

	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Move'
	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Size'
	DeleteMenu(hMenu, 2, MF_BYPOSITION); // disable 'Maximize'
}

/* //Ham nay von di dinh dung de xoa ca 3 nut nhung lai anh huong den viec phong to thu nho nen thoi
void ClearButtons()
{
	hConsole = GetConsoleWindow();
	long style = GetWindowLong(hConsole, GWL_STYLE);

	//style &= ~WS_SYSMENU;
	style &= ~WS_BORDER;
	SetWindowLongPtr(hConsole, GWL_STYLE, style);
}
*/

void DoiMauChu(short color)
{
	SetConsoleTextAttribute(hConsoleOutput, color);
}

void ChangeColorPallete(short NumberStyle)
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	//hConsoleOutput = GetActiveWindow();
	GetConsoleScreenBufferInfoEx(hConsoleOutput, &info);

	info.ColorTable[0] = MyColorPalette[NumberStyle].BackgroundColor; //Mau nen
	info.ColorTable[1] = MyColorPalette[NumberStyle].MainTextColor;	  //Mau chu 1 & Sieu nhan
	info.ColorTable[2] = MyColorPalette[NumberStyle].SecondTextColor; //Mau chu 2 & Cuc gach
	info.ColorTable[3] = MyColorPalette[NumberStyle].ThirdTextColor;  //Mau chu 3 & Loi thoat
	info.ColorTable[4] = MyColorPalette[NumberStyle].DisableColor;	  //Mau chua chon

	info.ColorTable[11] = RGB(250, 250, 250); //Trang*
	info.ColorTable[12] = RGB(12, 12, 12);	  //Den*
	info.ColorTable[13] = RGB(50, 120, 220);  //Xanh*
	info.ColorTable[14] = RGB(240, 50, 50);	  //Do*
	info.ColorTable[15] = RGB(255, 242, 0);	  //Vang*

	SetConsoleScreenBufferInfoEx(hConsoleOutput, &info);

	ResizeConsole(100, 40); //Chinh lai kich thuoc cho binh thuong

	//Xoa cai cu ghi cai moi
	Gotoxy(20, 5);
	std::cout << std::setw(20) << " ";
	Gotoxy(20, 5);
	std::cout << std::setw(20 - (20 - MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage].length()) / 2)
			  << MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage]; //Can giua
}

/*void ChangeFontAndSize()
{
	CONSOLE_FONT_INFOEX cfi;

	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;	//So thu tu cua font trong bang
	cfi.dwFontSize.X = 0;	// Width of each character in the font
	cfi.dwFontSize.Y = 16;	// Height

	cfi.FontFamily = FF_DONTCARE;	//Ho dech care
	cfi.FontWeight = FW_NORMAL;		//Kieu chu in thuong

	std::wcscpy_s(cfi.FaceName, L"Consolas");

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
*/

void PrintLevelNumber(short column, short row, short number, short bcolor)
{
	DWORD Garbage; //Thung rac thoi, khong can de y

	PrintMiniBlock(8, 3, 10 + 24 * column, short(10 + 11 * row));
	WORD color[3][8];
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			//Neu la ' ' thi ra mau nen, con lai ra 11
			short backgroundcolor = bcolor * (NumberInfo[2 * i][number / 10 * 3 + j] == ' ') + (NumberInfo[2 * i][number / 10 * 3 + j] != ' ') * 11;
			short foregroundcolor = bcolor * (NumberInfo[2 * i + 1][number / 10 * 3 + j] == ' ') + (NumberInfo[2 * i + 1][number / 10 * 3 + j] != ' ') * 11;
			color[i][j] = 16 * backgroundcolor + foregroundcolor;
		}
		for (short j = 0; j < 3; j++)
		{
			//Neu la ' ' thi ra mau nen, con lai ra 11
			short backgroundcolor = bcolor * (NumberInfo[2 * i][number % 10 * 3 + j] == ' ') + (NumberInfo[2 * i][number % 10 * 3 + j] != ' ') * 11;
			short foregroundcolor = bcolor * (NumberInfo[2 * i + 1][number % 10 * 3 + j] == ' ') + (NumberInfo[2 * i + 1][number % 10 * 3 + j] != ' ') * 11;
			color[i][j + 5] = 16 * backgroundcolor + foregroundcolor;
		}
		color[i][3] = color[i][4] = bcolor * 17;
	}
	for (short i = 0; i < 3; i++)
		WriteConsoleOutputAttribute(hConsoleOutput, color[i], 8, {short(10 + 24 * column), short(10 + 11 * row + i)}, &Garbage);
}

void PrintLogo(short x, short y, bool isSmall)
{
	if (isSmall)
	{
		//Tao lop nen cai da
		PrintMiniBlock(34, 4, x, y);

		DWORD Garbage; //Thung rac thoi, khong can de y
		for (short i = 0; i < 4; i++)
			WriteConsoleOutputAttribute(hConsoleOutput, LogoInfoColor[i], 34, {(short)x, (short)(y + i)}, &Garbage);
	}
	else
	{
		//Tao mot lop nen cai da
		PrintBlock(68, 8, x, y, 1);

		DWORD Garbage; //Thung rac thoi, khong can de y
		//Nhap mau cho logo
		WORD color[8][70];
		for (short i = 0; i < 8; i++)
			for (short j = 0; j < 34; j++)
				//Neu la ' ' thi ra mau nen, con lai thi ra no + 12
				color[i][2 * j] = color[i][2 * j + 1] = (LogoInfo[i][j] - '0' + 12) * (LogoInfo[i][j] != ' ') * 16;

		for (short i = 0; i < 8; i++)
			WriteConsoleOutputAttribute(hConsoleOutput, color[i], 68, {short(x), short(y + i)}, &Garbage);
	}
}

void PrintMiniBlock(short width, short height, short x, short y)
{
	DWORD Garbage; //Thung rac thoi, khong can de y

	for (short i = 0; i < height; i++)
		FillConsoleOutputCharacter(hConsoleOutput, 220, width, {(short)x, (short)(y + i)}, &Garbage);
}

void PrintBlock(short width, short height, short x, short y, short color)
{
	DWORD Garbage; //Thung rac thoi, khong can de y

	color *= 16; //Bien mau chinh thanh mau nen

	for (short i = 0; i < height; i++)
	{
		//Ham nay se in ra ky tu ' ' width lan, bat dau tu vi tri da chon.
		//Sau do ghi so ki tu thuc su duoc in vao bien Garbage.
		FillConsoleOutputCharacter(hConsoleOutput, ' ', width, {(short)x, (short)(y + i)}, &Garbage);
		//Con ham nay dung de to 1 mau duy nhat cho may ky tu do
		FillConsoleOutputAttribute(hConsoleOutput, color, width, {(short)x, (short)(y + i)}, &Garbage);
	}
}

void ColorBlock(short width, short height, short x, short y, short color)
{
	DWORD Garbage; //Thung rac thoi, khong can de y

	for (short i = 0; i < height; i++)
		FillConsoleOutputAttribute(hConsoleOutput, color, width, {(short)x, (short)(y + i)}, &Garbage);
}

void ChangeOptionNowcursor(bool isThemenow)
{
	DWORD Garbage; //Thung rac thoi, khong can quan tam

	//Hoa xam cai kia
	FillConsoleOutputAttribute(hConsoleOutput, 4, 50, {0, (short)(5 + 6 * isThemenow)}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 4, 22, {19, (short)(6 + 6 * isThemenow)}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 4, 22, {19, (short)(8 + 6 * isThemenow)}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 4, 1, {19, (short)(7 + 6 * isThemenow)}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 4, 1, {40, (short)(7 + 6 * isThemenow)}, &Garbage);
	Gotoxy(4, 5 + 6 * isThemenow);
	std::cout << " ";

	//Hoa xanh cai nay
	FillConsoleOutputAttribute(hConsoleOutput, 1, 50, {0, (short)(5 + 6 * (1 - isThemenow))}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 1, 22, {19, (short)(6 + 6 * (1 - isThemenow))}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 1, 22, {19, (short)(8 + 6 * (1 - isThemenow))}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 1, 1, {19, (short)(7 + 6 * (1 - isThemenow))}, &Garbage);
	FillConsoleOutputAttribute(hConsoleOutput, 1, 1, {40, (short)(7 + 6 * (1 - isThemenow))}, &Garbage);
	Gotoxy(4, 5 + 6 * (1 - isThemenow));
	std::cout << ">";
}

void MakeTable(short row, short column, short x, short y)
{
	//Kiem tra dieu kien
	if ((row <= 0) || (column <= 0))
		return;

	DWORD Garbage; //Thung rac thoi, khong can de y

	//Hang ngang
	{
		FillConsoleOutputCharacter(hConsoleOutput, (char)205, 4 * column + 1, {x, y}, &Garbage);
		FillConsoleOutputCharacter(hConsoleOutput, (char)205, 4 * column + 1, {x, (short)(y + 2 * row)}, &Garbage);
		for (short i = 1; i < row; i++)
			FillConsoleOutputCharacter(hConsoleOutput, (char)196, 4 * column + 1, {x, (short)(y + 2 * i)}, &Garbage);
	}

	//Cot doc
	{
		for (short i = 0; i < row; i++)
		{
			Gotoxy(x, y + 1 + 2 * i);
			std::cout << (char)186;
			Gotoxy(x + 4 * column, y + 1 + 2 * i);
			std::cout << (char)186;
		}
		for (short i = 1; i < column; i++)
		{
			for (short j = 0; j < row; j++)
			{
				Gotoxy(x + 4 * i, y + 1 + 2 * j);
				std::cout << '|';
			}
		}
	}

	//Goc
	{
		Gotoxy(x, y);
		std::cout << (char)201;
		Gotoxy(x, y + 2 * row);
		std::cout << (char)200;
		Gotoxy(x + 4 * column, y);
		std::cout << (char)187;
		Gotoxy(x + 4 * column, y + 2 * row);
		std::cout << (char)188;
	}

	//Canh
	{
		for (short i = 1; i < row; i++) //Canh doc
		{
			Gotoxy(x, y + 2 * i);
			std::cout << (char)204;
			Gotoxy(x + 4 * column, y + 2 * i);
			std::cout << (char)185;
		}
		for (short i = 1; i < column; i++) //Canh ngang
		{
			Gotoxy(x + 4 * i, y);
			std::cout << (char)203;
			Gotoxy(x + 4 * i, y + 2 * row);
			std::cout << (char)202;
		}
	}

	//Giao diem
	for (short i = 1; i < column; i++)
	{
		for (short j = 1; j < row; j++)
		{
			Gotoxy(x + 4 * i, y + 2 * j);
			std::cout << (char)197;
		}
	}
}