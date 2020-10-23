# **PrintMiniBlock**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
void PrintMiniBlock(short width, short height, short x, short y)
{
    DWORD Garbage; //Thung rac thoi, khong can de y

    for (short i = 0; i < height; i++)
        FillConsoleOutputCharacter(hConsoleOutput, 220, width, {(short)x, (short)(y + i)}, &Garbage);
}
```

## Tham số

- `width`
  - Kiểu `short`
  - Làm gì đó.

- `height`
  - Kiểu `short`
  - Làm gì đó.

- `x`
  - Kiểu `short`
  - Làm gì đó.

- `y`
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
