# **PrintLevelPage**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
void PrintLevelPage(short pagenumber)
{
    //Lop so nen
    for (short i = 0; i < 12; i++)
        PrintLevelNumber(i % 4, i / 4, i + 1 + pagenumber * 12, 4);

    //O vuong cuoi trang xanh
    {
        DoiMauChu(0x01);
        Gotoxy(13 + 24 * pagenumber, 38);
        std::cout << (char)220 << (char)220;
        Gotoxy(13 + 24 * pagenumber, 39);
        std::cout << (char)223 << (char)223;
    }
}
```

## Tham số

- `pagenumber`
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
