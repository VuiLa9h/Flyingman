# **GetKeyButton**

Hàm này có tác dụng trả về giá trị của phím mình nhập vào từ bàn phím.

## Ý tưởng

Nhập một kí tự vào từ bàn phím rồi trả về giá trị của nó.

## Code đầy đủ

```cpp
int GetKeyButton()
{
    int c = _getch();

    if (c == 0xE0) //Khi nhap phim mui ten, no se tra ve 2 gia tri. Dau tien la 0xE0, sau do moi den mui ten
    {
        c = _getch();
        return c;
    }

    if (c == 0) //Day phim f1, f2...
    {
        c = _getch();
        return _OTHER_KEY;
    }

    if ((c == _ESC_KEY) || (c == _ENTER_KEY) || (c == _SPACE_KEY) || (c == _TAB_KEY))
        return c;

    return _OTHER_KEY;
}
```

## Tham số

Không có gì.

## Những thứ khác

Không có gì.

## Lưu ý

`getch()` là một hàm đã lỗi thời, do đó người ta đề xuất sử dụng `_getch()`.

Khi mình nhập một ký tự mũi tên, nó sẽ trả về hai giá trị, một giá trị là 0xE0 và giá trị còn lại mới là giá trị thật của phím đó. Do đó nếu có số -32 thì ta phải `_getch()` thêm lần nữa. Với dãy phím Fn cũng vậy.

Danh sách các giá trị của các kí tự có thể xem ở [đây](../Console.md###Còn%20lại)

## Lan quyên

Cũng không có gì nốt.
