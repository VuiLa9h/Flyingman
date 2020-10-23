# **ResizeConsole**

Hàm này có tác dụng điều chỉnh kích cỡ cửa sổ bằng số hàng và số cột (tính theo ký tự).

## Code đầy đủ

```cpp
void ResizeConsole(short width, short height)
{
    SMALL_RECT windowSize = {0, 0, short(width - 1), short(height - 1)};
    SetConsoleWindowInfo(hConsoleOutput, true, &windowSize);
}
```

## Tham số

- `width`
  - Kiểu `short`
  - Xác định chiều ngang của cửa sổ (Hay là số cột).

- `height`
  - Kiểu `short`
  - Xác định chiều dọc của cửa sổ (Hay là số hàng).

## Những thứ khác

- `windowSize`
  - Kiểu `SMALL_RECT`
  - Xác định vị trí của cửa số, tính theo bộ đệm.

- `SetConsoleWindowInfo`
  - Hàm số dùng để đặt thuộc tính cho cửa số, ở trường hợp này là `windowsSize`
  - Chi tiết xem tại [đây](https://docs.microsoft.com/en-us/windows/console/setconsolewindowinfo).

## Lưu ý

Cửa số và bộ đệm phải có kích thước tương tự nhau, không thì ít nhất bộ đệm cũng phải to hơn cửa sổ, nếu không sẽ sai lệch.

## Lan quyên

[ResizeScreenBuffer](ResizeScreenBuffer.md)
