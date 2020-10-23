# **ChangeLevelSelect**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
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
```

## Tham số

- `previouslevel`
  - Kiểu `short`
  - Làm gì đó.

- `nowlevel`
  - Kiểu `short`
  - Làm gì đó.

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
