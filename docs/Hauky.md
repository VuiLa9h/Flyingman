# **Hau ky**

Đây là nơi chứa tất cả những gì bạn cần về các hàm trong Hauky

## **Những giá trị cần biết**

Chưa rõ

---

## **Phongcachthoitrang**

Bài chi tiết: [Phongcachthoitrang](Hauky/Phongcachthoitrang.md)

Hàm này có tác dụng điều chỉnh kích cỡ cửa sổ bằng số hàng và số cột (tính theo ký tự)

Cú pháp của hàm `Phongcachthoitrang` như sau:

```cpp
void Phongcachthoitrang();
```

---

## **PrintMainLayout**

Bài chi tiết: [PrintMainLayout](Hauky/Main.md)

Hàm này dùng để in lớp nền cho menu chính.

Cú pháp của hàm `PrintMainLayout` như sau:

```cpp
void PrintMainLayout();
```

---

## **ChangeMainSelect**

Bài chi tiết: [ChangeMainSelect](Hauky/Main.md)

Hàm này có tác dụng đổi vị trí của ô đang chọn trong menu chính.

Cú pháp của hàm `ChangeMainSelect` như sau:

```cpp
void ChangeMainSelect(short previousmain, short nowmain);
```

Tham số:

- `previousmain`
  - Kiểu `short`
  - Level trước khi chuyển.

- `nowmain`
  - Kiểu `short`
  - Level sau khi chuyển.

---

## **PrintLevelLayout**

Bài chi tiết: [PrintLevelLayout](Hauky/Level.md)

Hàm này dùng để in lớp nền cho trang chọn màn chơi.

Cú pháp của hàm `PrintLevelLayout` như sau:

```cpp
void PrintLevelLayout();
```

---

## **PrintLevelPage**

Bài chi tiết: [PrintLevelPage](Hauky/Level.md)

Hàm này có tác dụng in số minh họa cho trang đang chọn.

Cú pháp của hàm `PrintLevelPage` như sau:

```cpp
void PrintLevelPage(short pagenumber);
```

Tham số:

- `pagenumber`
  - Kiểu `short`
  - Trang hiện tại.

---

## **ChangeLevelSelect**

Bài chi tiết: [ChangeLevelSelect](Hauky/Level.md)

Hàm này có tác dụng in số minh họa cho trang đang chọn.

Cú pháp của hàm `ChangeLevelSelect` như sau:

```cpp
void ChangeLevelSelect(short previouslevel, short nowlevel);
```

Tham số:

- `previouslevel`
  - Kiểu `short`
  - Level cũ.

- `nowlevel`
  - Kiểu `short`
  - Level mới.

---
