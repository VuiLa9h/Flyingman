# **ChangeColorPallete**

Hàm này có tác dụng đổi giao diện cho ghêm.

## Ý tưởng

Lấy thông tin cửa số, thay đổi giá trị màu, cuối cùng gán lại vào cửa sổ cũ.

## Code đầy đủ

```cpp
void ChangeColorPallete(short NumberStyle)
{
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    //hConsoleOutput = GetActiveWindow();
    GetConsoleScreenBufferInfoEx(hConsoleOutput, &info);

    info.ColorTable[0] = MyColorPalette[NumberStyle].BackgroundColor; //Mau nen
    info.ColorTable[1] = MyColorPalette[NumberStyle].MainTextColor;   //Mau chu 1 & Sieu nhan
    info.ColorTable[2] = MyColorPalette[NumberStyle].SecondTextColor; //Mau chu 2 & Cuc gach
    info.ColorTable[3] = MyColorPalette[NumberStyle].ThirdTextColor;  //Mau chu 3 & Loi thoat
    info.ColorTable[4] = MyColorPalette[NumberStyle].DisableColor;    //Mau chua chon

    info.ColorTable[11] = RGB(250, 250, 250); //Trang*
    info.ColorTable[12] = RGB(12, 12, 12);    //Den*
    info.ColorTable[13] = RGB(50, 120, 220);  //Xanh*
    info.ColorTable[14] = RGB(240, 50, 50);   //Do*
    info.ColorTable[15] = RGB(255, 242, 0);   //Vang*

    SetConsoleScreenBufferInfoEx(hConsoleOutput, &info);

    ResizeConsole(100, 40); //Chinh lai kich thuoc cho binh thuong

    //Xoa cai cu ghi cai moi
    Gotoxy(20, 5);
    std::cout << std::setw(20) << " ";
    Gotoxy(20, 5);
    std::cout << std::setw(20 - (20 - MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage].length()) / 2)
              << MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage]; //Can giua
}
```

## Tham số

- `NumberStyle`
  - Kiểu `short`
  - Số thứ tự quy định kiểu mình muốn đổi, được sắp xếp từ 0 tới n trong file `Theme.dat`.

## Những thứ khác

- `info`
  - Kiểu `CONSOLE_SCREEN_BUFFER_INFOEX`
  - Nơi chứa thông tin của cửa sổ, bao gồm nhiều thứ linh tinh, trong đó có màu sắc. Xem thêm tại [đây](https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-infoex).

- `GetConsoleScreenBufferInfoEx` & `SetConsoleScreenBufferInfoEx`
  - Lấy và đặt thuộc tính cho cửa sổ, bao gồm một vài tiện ích mở rộng. Xem thêm tại [đây](https://docs.microsoft.com/en-us/windows/console/getconsolescreenbufferinfoex) và [đây](https://docs.microsoft.com/en-us/windows/console/setconsolescreenbufferinfoex).

## Lưu ý

Hàm `GetConsoleScreenBufferInfoEx` (và cả những hàm Ex) chỉ có tác dụng với Windows Vista trở về sau.  
Mặc định thư viện của vscode là Windows 2k < Windows Vista nên không dùng được.  
Để sửa lỗi này ta phải khai rằng mình đang ở Windows >= 7 bằng cách thay biến `_WIN32_WINNT` thành `_WIN32_WINNT_WIN7` (`sdkddkver.h`, dòng 185), chi tiết xem tại [đây](https://docs.microsoft.com/en-gb/windows/win32/winprog/using-the-windows-headers).

Vì lí do gì đó, sau khi chuyển màu hệ thống thì cửa sổ bị thu nhỏ, do đó ta phải chỉnh lại kích thước cho bình thường.

Muốn dùng `std::setw()` thì phải có thư viện `iomanip`.

## Lan quyên

Cũng không có gì nốt.
