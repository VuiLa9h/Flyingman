# **PrintPlayLayout**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
void PrintPlayLayout(short Levelnumber)
{
    DoiMauChu(0x01);
    Gotoxy(4, 1);
    std::cout << Language[UserNowData.Nowlanguage].LevelList[0] << ": " << Levelnumber << "\n";
    Gotoxy(83, 1);
    std::cout << Language[UserNowData.Nowlanguage].LevelList[2] << ":\n";
    for (short i = 0; i < 100; i++)
        std::cout << (char)95;
    Gotoxy(2 * Level[Levelnumber].Man.X, Level[Levelnumber].Man.Y);
    std::cout << "><";
    Gotoxy(2 * Level[Levelnumber].Des.X, Level[Levelnumber].Des.Y);
    std::cout << "[]";

    DoiMauChu(0x02);
    for (int i = 0; i < Level[Levelnumber].BlockNum; i++)
    {
        Gotoxy(2 * Level[Levelnumber].Block[i].X, Level[Levelnumber].Block[i].Y);
        std::cout << (char)219 << (char)219;
    }

    if (Level[Levelnumber].isHole)
    {
        DoiMauChu(0x03);
        Gotoxy(2 * Level[Levelnumber].Hole[0].X, Level[Levelnumber].Hole[0].Y);
        std::cout << "()";
        Gotoxy(2 * Level[Levelnumber].Hole[1].X, Level[Levelnumber].Hole[1].Y);
        std::cout << "()";
    }
}
```

## Tham số

- `Levelnumber`
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
