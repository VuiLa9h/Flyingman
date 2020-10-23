# **PrintOptionLayout**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
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
    Gotoxy(20, 11);  //Tieng Viet, English
    std::cout << std::setw(20 - (20 - Language[UserNowData.Nowlanguage].OptionList[3].length()) / 2)
              << Language[UserNowData.Nowlanguage].OptionList[3];

    Gotoxy(20, 5);
    std::cout << std::setw(20) << " "; //Cach cach
    Gotoxy(20, 5);   //Ten phong cach
    std::cout << std::setw(20 - (20 - MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage].length()) / 2)
              << MyColorPalette[UserNowData.Nowtheme].StyleName[UserNowData.Nowlanguage]; //Can giua

    DoiMauChu(0x01); //Tra lai mau cho em
}
```

## Tham số

- `isFirst`
  - Kiểu `bool`
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
