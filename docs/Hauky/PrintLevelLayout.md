# **PrintLevelLayout**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
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
```

## Tham số

Không có gì.

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
