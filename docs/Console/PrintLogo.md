# **PrintLogo**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
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
```

## Tham số

- `x`
  - Kiểu `short`
  - Làm gì đó.

- `y`
  - Kiểu `short`
  - Làm gì đó.

- `isSmall`
  - Kiểu `bool`
  - Làm gì đó.

## Những thứ khác

Không có gì

## Lưu ý

Không có gì.

## Lan quyên

Cũng không có gì nốt.
