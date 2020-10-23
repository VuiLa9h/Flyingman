# **Console**

Đây là nơi chứa tât cả những hàm xử lý ở mức độ thấp nhất của game, ví dụ như chỉnh kích cỡ, xóa trang, v.v...

## **Những giá trị cần biết**

Trước khi vào bài, chúng ta cần biết những giá trị sau:

### **hConsoleOutput**

- Kiểu: `HANDLE`
- Được khai báo như sau:

```cpp
HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
```

**Ý nghĩa**: Biến này được dùng để **chỉ đến** của sổ hiện tại của mình

### **hConsole**

- Kiểu: `HWND`
- Được khai báo như sau:

```cpp
HWND hConsole;
```

**Ý nghĩa**: Biến này được dùng để **chỉ đến** của sổ hiện tại của mình, dùng trong hàm [DisableResize](##DisableResize)

### **mii**

- Kiểu: `MENUITEMINFO`
- Được khai báo như sau:

```cpp
MENUITEMINFO mii;
```

**Ý nghĩa**: Biến này dùng để lưu giữ thuộc tính của menu hệ thống, dùng trong hàm [DisableResize](##DisableResize)

### **Còn lại**

Ngoài những cái trên, chúng ta còn những hằng số sau:

| Tên| Ý nghĩa | Giá trị |
|:--- |:--- |:---:|
|`_ESC_KEY` | Giá trị của phím `ESC` | 27 |
|`_ENTER_KEY` | Giá trị của phím `Enter` | 13 |
|`_SPACE_KEY` | Giá trị của phím `cách` | 32 |
|`_TAB_KEY` | Giá trị của phím `TAB` | 9 |
|`_UP_KEY` | Giá trị của phím `lên` | 72 |
|`_DOWN_KEY` | Giá trị của phím `xuống` | 80 |
|`_RIGHT_KEY` | Giá trị của phím `phải` | 77 |
|`_LEFT_KEY` | Giá trị của phím `trái` | 75 |
|`_OTHER_KEY` | Giá trị của những phím còn lại | 0 |

---

## **ResizeConsole**

Bài chi tiết: [ResizeConsole](Console/ResizeConsole.md)

Hàm này có tác dụng điều chỉnh kích cỡ cửa sổ bằng số hàng và số cột (tính theo ký tự)

Cú pháp của hàm `ResizeConsole` như sau:

```cpp
void ResizeConsole(short width, short height);
```

Tham số:

- `width`
  - Kiểu `short`
  - Xác định chiều ngang của cửa sổ (Hay là số cột)

- `height`
  - Kiểu `short`
  - Xác định chiều dọc của cửa sổ (Hay là số hàng)

---

## **ResizeScreenBuffer**

Bài chi tiết: [ResizeScreenBuffer](Console/ResizeScreenBuffer.md)

Hàm này có tác dụng điều chỉnh kích thước bộ đệm (cũng tính theo ký tự)

Cú pháp của hàm `ResizeScreenBuffer` như sau:

```cpp
void ResizeScreenBuffer(short width, short height);
```

Tham số:

- `width`
  - Kiểu `short`
  - Xác định chiều ngang của bộ đệm (Hay là số cột).

- `height`
  - Kiểu `short`
  - Xác định chiều dọc của bộ đệm (Hay là số hàng).

Lưu ý:

- Bộ đệm là cái vùng mà chúng ta viết lên màn hình.
- Ta thấy cái cửa số cmd nó có thanh cuộn dài ngoằng như vậy vì bộ đệm của nó có tận 9000 hàng (wow).
- Trong khi đó, bộ đệm của ghêm này chỉ có 40 hàng mà thôi.

---

## **Gotoxy**

Bài chi tiết: [Gotoxy](Console/Gotoxy.md)

Hàm này thì quá nổi tiếng rồi, không nói chắc ai cũng biết.  
Chức năng chính của nó là di chuyển con trỏ của mình đến một vị trí trên màn hình.

Cú pháp của hàm `Gotoxy` như sau:

```cpp
void Gotoxy(short x, short y);
```

Tham số:

- `x`
  - Kiểu `short`
  - Xác định hoành độ con trỏ

- `y`
  - Kiểu `short`
  - Xác định tung độ của con trỏ

---

## **ShowCursor**

Cú pháp của hàm `ShowCursor` như sau:

```cpp
void ShowCursor(bool CursorVisibility);
```

Tham số:

- `CursorVisibility`

  - Kiểu: `bool`
  - Nếu là `true` thì con trỏ được hiển thị nhấp nháy, còn nếu là `false` thì ta sẽ không nhìn thấy con trỏ đâu hết.

---

## **GetKeyButton**

Cú pháp của hàm `GetKeyButton` như sau:

```cpp
int GetKeyButton();
```

---

## **DisableResize**

Cú pháp của hàm `DisableResize` như sau:

```cpp
void DisableResize();
```

---

## **ClearButtons**

Cú pháp của hàm `ClearButtons` như sau:

```cpp
void ClearButtons();
```

---

## **DoiMauChu**

Cú pháp của hàm `DoiMauChu` như sau:

```cpp
void DoiMauChu(short color);
```

---

## **ChangeColorPallete**

Cú pháp của hàm `ChangeColorPallete` như sau:

```cpp
void ChangeColorPallete(short NumberStyle);
```

---

## **ChangeFontAndSize**

Cú pháp của hàm `ChangeFontAndSize` như sau:

```cpp
void ChangeFontAndSize();
```

---

## **PrintLevelNumber**

Bài chi tiết: [PrintLevelNumber](Console/PrintLevelNumber.md)

Cú pháp của hàm `PrintLevelNumber` như sau:

```cpp
void PrintLevelNumber(short col, short row, short number, short bcolor);
```

---

## **PrintLogo**

Bài chi tiết: [PrintLogo](Console/PrintLogo.md)

Cú pháp của hàm `PrintLogo` như sau:

```cpp
void PrintLogo(short x, short y, bool isSmall);
```

---

## **PrintMiniBlock**

Bài chi tiết: [PrintMiniBlock](Console/PrintMiniBlock.md)

Cú pháp của hàm `PrintMiniBlock` như sau:

```cpp
void PrintMiniBlock(short width, short height, short x, short y);
```

---

## **PrintBlock**

Bài chi tiết: [PrintBlock](Console/PrintBlock.md)

Cú pháp của hàm `PrintBlock` như sau:

```cpp
void PrintBlock(short width, short height, short x, short y, short color);
```

---

## **ChangeOptionNowcursor**

Bài chi tiết: [ChangeOptionNowcursor](Console/ChangeOptionNowcursor.md)

Cú pháp của hàm `ChangeOptionNowcursor` như sau:

```cpp
void ChangeOptionNowcursor(bool isThemenow);
```

---

## **MakeTable**

Bài chi tiết: [MakeTable](Console/MakeTable.md)

Hàm này có tác dụng tao ra một bảng nhiều ô vuông như ta mong muốn, tại vị trí (x, y) trên màn hình.

Cú pháp của hàm `MakeTable` như sau:

```cpp
void MakeTable(short row, short column, short x, short y);
```
