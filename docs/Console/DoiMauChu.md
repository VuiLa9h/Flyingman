# **DoiMauChu**

Hàm này có tác dụng đổi màu chữ cũng như màu nền của những chữ chuẩn bị được in ra màn hình.

## Ý tưởng

Dùng `SetConsoleTextAttribute` để đổi màu chữ.

## Code đầy đủ

```cpp
void DoiMauChu(short color)
{
    SetConsoleTextAttribute(hConsoleOutput, color);
}
```

## Tham số

- `color`
  - Kiểu `short`
  - Quy định màu của chữ, cũng như màu nền.

## Những thứ khác

Không có gì.

## Lưu ý

Thông thường tui để `color` dưới dạng 0xAB, vì biểu diễn kiểu thập lục sẽ dễ hiểu hơn. (A là màu nền, B là màu chữ).

## Lan quyên

Cũng không có gì nốt.
