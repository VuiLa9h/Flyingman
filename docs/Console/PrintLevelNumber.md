# **PrintLevelNumber**

Hàm này có tác dụng in số cho lớp nên, thuộc trang Level.

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
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
```

## Tham số

- `column`
  - Kiểu `short`
  - Làm gì đó.

- `row`
  - Kiểu `short`
  - Làm gì đó.

- `number`
  - Kiểu `short`
  - Số.

- `bcolor`
  - Kiểu `short`
  - Màu nền của số.

## Những thứ khác

- `1`
  - Kiểu `int`
  - Làm gì đó.

- `2`
  - Kiểu `int`
  - Làm gì đó.

## Lưu ý

Không có gì.

## Lan quyên

Cũng không có gì nốt.
