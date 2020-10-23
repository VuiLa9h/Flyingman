# **Endgame**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
bool Endgame(bool isWin, int Score)
{
    bool out = false; //Muon ngung hay la khong?

    DoiMauChu(0x41);
    PrintBlock(40, 16, 30, 12, 4);
    Gotoxy(30, 14);
    for (int i = 0; i < 40; i++)
        std::cout << (char)95;
    Gotoxy(30, 24);
    for (int i = 0; i < 40; i++)
        std::cout << (char)95;

    if (isWin)
    {
        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[0].length() / 2, 13);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[0];
        Gotoxy(40 - Language[UserNowData.Nowlanguage].PlayList[3].length() / 2, 26);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[3];
        Gotoxy(60 - Language[UserNowData.Nowlanguage].PlayList[2].length() / 2, 26);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[2];

        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[5].length() / 2, 18);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[5];
        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[6].length() / 2, 20);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[6];
        Gotoxy(49, 21);
        std::cout << Score;
    }
    else
    {
        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[1].length() / 2, 13);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[1];
        Gotoxy(40 - Language[UserNowData.Nowlanguage].PlayList[4].length() / 2, 26);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[4];
        Gotoxy(60 - Language[UserNowData.Nowlanguage].PlayList[2].length() / 2, 26);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[2];

        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[7].length() / 2, 18);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[7];
        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[8].length() / 2, 20);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[8];
        Gotoxy(50 - Language[UserNowData.Nowlanguage].PlayList[9].length() / 2, 21);
        std::cout << Language[UserNowData.Nowlanguage].PlayList[9];
    }

    ColorBlock(20, 3, 30 + 20 * out, 25, 0x14); //Hoa xanh lan dau

    while (true)
    {
        int Key = GetKeyButton();
        if (Key == _ESC_KEY)
            return false;
        else if (Key == _ENTER_KEY || Key == _SPACE_KEY)
            return out;

        else if (Key == _LEFT_KEY || Key == _RIGHT_KEY)
        {
            ColorBlock(20, 3, 30 + 20 * out, 25, 0x41); //Hoa den cai cu
            out = 1 - out;
            ColorBlock(20, 3, 30 + 20 * out, 25, 0x14); //Hoa xanh cai moi
        }
    }
}
```

## Tham số

- `isWin`
  - Kiểu `bool`
  - Làm gì đó.

- `Score`
  - Kiểu `int`
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
