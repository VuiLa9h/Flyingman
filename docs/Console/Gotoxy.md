# **Gotoxy**

Hàm này thì quá nổi tiếng rồi, không nói chắc ai cũng biết.  
Chức năng chính của nó là di chuyển con trỏ của mình đến một vị trí trên màn hình.

## Ý tưởng

Dùng `SetConsoleCursorPosition` để chỉnh lại vị trí của con trỏ.

## Code đầy đủ

```cpp
void Gotoxy(short x, short y)
{
    COORD Cursor_an_Pos = {(short)x, (short)y};
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
```

## Tham số

- `x`
  - Kiểu `short`
  - Hoành độ của con trỏ (tính từ 0).

- `y`
  - Kiểu `short`
  - Tung độ của con trỏ (tính từ 0).

## Những thứ khác

- `Cursor_an_Pos`
  - Kiểu `COORD`
  - Tọa độ của con trỏ nhưng lưu theo biến `COORD`.

## Lưu ý

`COORD` thì cũng chỉ là 2 số kiểu `short` mà thôi, nhưng dùng nó sẽ tường minh và dễ hiểu hơn ^^.

## Lan quyên

Cũng không có gì nốt.
