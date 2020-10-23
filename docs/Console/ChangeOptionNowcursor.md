# **ChangeOptionNowcursor**

Hàm này có tác dụng chuyển đổi con trỏ giữa "phong cách" và "ngôn ngữ", một phần của trang cài đặt.

## Ý tưởng

Đầu tiên biến hết tất cả những dòng của phần cài đặt cũ sang màu `disable`  
Sau đó biến hết tất cả những dòng của phần cài đặt mới sang màu `main`

## Code đầy đủ

```cpp
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
```

## Tham số

- `isThemenow`
  - Kiểu `bool`
  - Xác định xem con trỏ bây giờ có phải đang ở phần giao diện hay không.

## Những thứ khác

- `Garbage`
  - Kiểu `DWORD`
  - Thùng rác thôi, không cần quan tâm.

## Lưu ý

Hàm `FillConsoleOutputAttribute` dùng để in một loạt MÀU giống nhau cho các chữ cái liên tiếp. Chi tiết xem tại [đây](https://docs.microsoft.com/en-us/windows/console/fillconsoleoutputattribute).

Đáng lẽ ra cái này nằm ở Hauky.cpp, nhưng nó yêu cầu nhiều tác vụ sâu hơn nên tui chuyển vào đây.

## Lan quyên

Cũng không có gì nốt.
