# **PrintMainLayout**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
void PrintMainLayout()
{
    PrintLogo(16, 4, false);

    Gotoxy(2, 38);
    std::cout << std::setw(96) << Language[UserNowData.Nowlanguage].CreditList[4];
    Gotoxy(2, 38);
    std::cout << Language[UserNowData.Nowlanguage].CreditList[3];

    for (int i = 0; i < 5; i++)
    {
        PrintBlock(30, 3, 35, 14 + i * 4, 0);
        Gotoxy(35, 15 + 4 * i);
        std::cout << std::setw(27) << Language[UserNowData.Nowlanguage].MenuList[i];
    }
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
