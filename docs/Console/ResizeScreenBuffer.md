# **ResizeScreenBuffer**

Hàm này có tác dụng điều chỉnh kích cỡ bộ đệm bằng số hàng và số cột (tính theo ký tự).

## Code đầy đủ

```cpp
void ResizeScreenBuffer(short width, short height)
{
    COORD bufferSize = {width, height};
    SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);
}
```

## Tham số

- `width`
  - Kiểu `short`
  - Xác định chiều ngang của bộ đệm (Hay là số cột).

- `height`
  - Kiểu `short`
  - Xác định chiều dọc của bộ đệm (Hay là số hàng).

## Những thứ khác

- `bufferSize`
  - Kiểu `COORD`
  - Xác định kích thước của bộ đệm, tính theo ký tự.

- `SetConsoleScreenBufferSize`
  - Hàm số dùng để đặt kích cỡ cho bộ đệm.
  - Chi tiết xem tại [đây](https://docs.microsoft.com/en-us/windows/console/setconsolewindowinfo).

## Lưu ý

Cửa số và bộ đệm phải có kích thước tương tự nhau, không thì ít nhất bộ đệm cũng phải to hơn cửa sổ, nếu không sẽ sai lệch.

## Lan quyên

[ResizeConsole](ResizeConsole.md)
