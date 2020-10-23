# **ColorBlock**

Hàm này có tác dụng in MÀU cho một khối ký tự có kích thước cho trước, bắt nguồn từ một vị trí cho trước, với một màu cho trước.

## Ý tưởng

Dùng `FillConsoleOutputAttribute` để in màu cho một loạt ký tự liên tiếp, làm đi làm lại nhiều dòng.

## Code đầy đủ

```cpp
void ColorBlock(short width, short height, short x, short y, short color)
{
    DWORD Garbage; //Thung rac thoi, khong can de y

    for (short i = 0; i < height; i++)
        FillConsoleOutputAttribute(hConsoleOutput, color, width, {(short)x, (short)(y + i)}, &Garbage);
}
```

## Tham số

- `width`
  - Kiểu `short`
  - Số cột của mảng, tính theo số ký tự.

- `height`
  - Kiểu `short`
  - Số dòng của mảng, cũng tính theo số ký tự.

- `x`
  - Kiểu `short`
  - Hoành độ của vị trí bắt đầu, tính từ 0.

- `y`
  - Kiểu `short`
  - Tung độ của vị trí bắt đầu, tính từ 0.

- `color`
  - Kiểu `short`
  - Màu.

## Những thứ khác

- `Garbage`
  - Kiểu `DWORD`
  - Thùng rác thôi, không cần quan tâm.

## Lưu ý

Hàm `FillConsoleOutputAttribute` dùng để in một loạt MÀU giống nhau cho các chữ cái liên tiếp. Chi tiết xem tại [đây](https://docs.microsoft.com/en-us/windows/console/fillconsoleoutputattribute).

## Lan quyên

Cũng không có gì nốt.
