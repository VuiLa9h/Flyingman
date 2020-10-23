#ifndef _CONSOLE_H
#define _CONSOLE_H
/**/
#define _ESC_KEY 27
#define _ENTER_KEY 13
#define _SPACE_KEY 32
#define _TAB_KEY 9

#define _UP_KEY 72
#define _DOWN_KEY 80
#define _RIGHT_KEY 77
#define _LEFT_KEY 75

#define _OTHER_KEY 0

//Dieu chinh kich co cua so
void ResizeConsole(short width, short height);
//Dieu chinh kich co vung ky tu
void ResizeScreenBuffer(short width, short height);
/*
Note: Kich co vung ky tu phai >= kich co cua so, neu khong se bi sai.
*/

//Di chuyen vi tri con tro
void Gotoxy(short x, short y);
//Tat chuot di
void ShowCursor(bool CursorVisibility);
//Lay gia tri ban phim
int GetKeyButton();
//Han che dieu chinh kich co lung tung
void DisableResize();
//Doi mau chu
void DoiMauChu(short color);
//Doi mau he thong game
//Doc (*) de biet them thong tin chi tiet
void ChangeColorPallete(short NumberStyle);

//Thay doi font va co chu
//void ChangeFontAndSize();

//In "so" vao o vuong da cho voi mau nen (chi ap dung cho chon level)
void PrintLevelNumber(short col, short row, short number, short bcolor);

//In logo, neu true thi la logo be, false thi la logo to
void PrintLogo(short x, short y, bool isSmall);

//In mot khoi ki tu "vuong" theo kich co va vi tri cho san
void PrintMiniBlock(short width, short height, short x, short y);

//In mot khoi theo kich co, vi tri va mau cho san, xac dinh xem do la nen hay chinh
//De phan biet giua A va W, doc (**)
void PrintBlock(short width, short height, short x, short y, short color);
//Boi mau cho mot khu vuc nao day
void ColorBlock(short width, short height, short x, short y, short color);

//Chuyen doi cai dat giua phong cach va ngon ngu
//Dang le ra o Hauky nhung cai nay yeu cau sau hon nen nem vao day
void ChangeOptionNowcursor(bool isThemenow);

//In ra mot bang tai vi tri {x, y}
void MakeTable(short row, short column, short x, short y);

#endif

/*
Ham GetConsoleScreenBufferInfoEx (va ca nhung ham Ex) chi co tac dung voi Windows Vista tro len.
Mac dinh thu vien cua vscode la Windows 2k < Windows Vista nen khong the dung duoc.
De sua loi nay ta phai khai rang minh dang o Windows >=7 bang cach thay bien _WIN32_WINNT thanh _WIN32_WINNT_WIN7 (sdkddkver.h, dong 185)
Chi tiet xem tai day:
https://docs.microsoft.com/en-gb/windows/win32/winprog/using-the-windows-headers

Luu y: Vi mot li do kho hieu gi do ma moi lan doi mau thi cua so lai bi thu nho di 1 don vi.
The nen moi lan doi mau la mot lan doi kich co.
*/

/**
 * Moi ham in thuong co 2 dang, WriteOutputA va WriteOutputW, vay no khac nhau o dau?
 * Chi khac nhau o cho o A dung kieu WORD - chu thong thuong con W dung kieu DWORD - ho tro them cac chu tieng Viet tieng Nhat v.v...
 * Mac dinh neu minh khong ghi gi thi no se ngam hieu la W;
**/