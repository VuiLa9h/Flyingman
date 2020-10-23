# **GetLanguagePack**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetLanguagePack

Hàm này có tác dụng khởi tạo thông tin ban đầu về các dòng chữ trong ghêm, với `0` là Tiếng Việt và `1` là Tiếng Anh.

## Ý tưởng

Gán.

## Code đầy đủ

```cpp
void GetLanguagePack()
{
    Language[0].Label = "Vi";

    Language[0].MenuList[0] = "    BAT DAU TRO CHOI    ";
    Language[0].MenuList[1] = " CAU CHUYEN & HUONG DAN ";
    Language[0].MenuList[2] = " PHONG CACH THOI THUONG ";
    Language[0].MenuList[3] = "     GA KEO TAC GIA     ";
    Language[0].MenuList[4] = "    VANG RA CHUONG GA   ";

    Language[0].LevelList[0] = "Man choi";
    Language[0].LevelList[1] = "Do kho";
    Language[0].LevelList[2] = "Diem cao";

    Language[0].PlayList[0] = "THANG ROI, GIOI QUA DI :O";
    Language[0].PlayList[1] = "THUA MAT ROI :((";
    Language[0].PlayList[2] = "VE MENU CHINH";
    Language[0].PlayList[3] = "CHOI TIEP";
    Language[0].PlayList[4] = "CHOI LAI";
    Language[0].PlayList[5] = "Xin chuc mung, Chau Bui!";
    Language[0].PlayList[6] = "Diem so cua ban la";
    Language[0].PlayList[7] = "Con ong ba choi ngu nhu bo!";
    Language[0].PlayList[8] = "Toi that khong the hieu noi";
    Language[0].PlayList[9] = "ong ba co biet day con khong nua?";

    Language[0].StoryList[0] = "Huong dan su dung";
    Language[0].StoryList[1] = "An TAB/SPACE/ENTER de chuyen trang";

    Language[0].OptionList[0] = "Cai dat";
    Language[0].OptionList[1] = "Phong cach";
    Language[0].OptionList[2] = "Ngon ngu";
    Language[0].OptionList[3] = "Tieng Viet";
    Language[0].OptionList[4] = "An ESC de thoat";

    Language[0].CreditList[0] = "Tac gia & Tac pham";
    Language[0].CreditList[1] = "Hiep sy khong gian";
    Language[0].CreditList[2] = "Version: 1.0.0";
    Language[0].CreditList[3] = "(C) 2001 - 2020, Vtysvt Inc";
    Language[0].CreditList[4] = "Made by CrazyrabVn & Light Bro Animation";
    Language[0].CreditList[5] = "An ESC de thoat";
    Language[0].CreditList[6] = "An Enter de ga dam nhau voi tac gia";

    Language[0].CreditList[7] = "Chiu trach nhiem san xuat";
    Language[0].CreditList[8] = "Khung chuong trinh";
    Language[0].CreditList[9] = "Cot truyen";
    Language[0].CreditList[10] = "Thiet ke man choi";
    Language[0].CreditList[11] = "Giao dien nguoi dung";
    Language[0].CreditList[12] = "Thuat toan";
    Language[0].CreditList[13] = "Ky xao, hieu ung";
    Language[0].CreditList[14] = "Hau ky";
    Language[0].CreditList[15] = "Dich thuat";
    Language[0].CreditList[16] = "Huong dan su dung";
    Language[0].CreditList[17] = "Choi thu va loi sml";
    Language[0].CreditList[18] = "Quang cao";

    /**/ /**/ /**/ /**/

    Language[1].Label = "En";

    Language[1].MenuList[0] = "       START GAME       ";
    Language[1].MenuList[1] = "    STORY & GUIDANCE    ";
    Language[1].MenuList[2] = "    LANGUAGE & STYLE    ";
    Language[1].MenuList[3] = "         CREDIT         ";
    Language[1].MenuList[4] = "        END GAME        ";

    Language[1].LevelList[0] = "Level";
    Language[1].LevelList[1] = "Difficult";
    Language[1].LevelList[2] = "Score";

    Language[1].PlayList[0] = "YOU ARE WINNER!";
    Language[1].PlayList[1] = "YOU ARE LOSER!";
    Language[1].PlayList[2] = "GO TO MENU";
    Language[1].PlayList[3] = "NEXT LEVEL";
    Language[1].PlayList[4] = "REPLAY";
    Language[1].PlayList[5] = "Congratulation, Chau Bui!";
    Language[1].PlayList[6] = "Your score is";
    Language[1].PlayList[7] = "Con ong ba choi ngu nhu bo!";
    Language[1].PlayList[8] = "Toi that khong the hieu noi";
    Language[1].PlayList[9] = "ong ba co biet day con khong nua?";

    Language[1].StoryList[0] = "Story and guidance";
    Language[1].StoryList[1] = "Press TAB/SPACE/ENTER to go to next page";

    Language[1].OptionList[0] = "Setting";
    Language[1].OptionList[1] = "Theme";
    Language[1].OptionList[2] = "Language";
    Language[1].OptionList[3] = "English";
    Language[1].OptionList[4] = "Press ESC to exit";

    Language[1].CreditList[0] = "Credit";
    Language[1].CreditList[1] = "Flying Man";
    Language[1].CreditList[2] = "Version: 1.0.0";
    Language[1].CreditList[3] = "(C) 2001 - 2020, Vtysvt Inc";
    Language[1].CreditList[4] = "Made by CrazyrabVn & Light Bro Animation";
    Language[1].CreditList[5] = "Press ESC to exit";
    Language[1].CreditList[6] = "Press Enter to go to author's page";

    Language[1].CreditList[7] = "Producer";
    Language[1].CreditList[8] = "Program bone";
    Language[1].CreditList[9] = "Story";
    Language[1].CreditList[10] = "Level design";
    Language[1].CreditList[11] = "UI / UX";
    Language[1].CreditList[12] = "Algorithm";
    Language[1].CreditList[13] = "Visual FX";
    Language[1].CreditList[14] = "Editor";
    Language[1].CreditList[15] = "Translator";
    Language[1].CreditList[16] = "Write documents";
    Language[1].CreditList[17] = "Tester";
    Language[1].CreditList[18] = "Marketing";
}
```

## Lan quyên

[Language](../Material.md#Language)
