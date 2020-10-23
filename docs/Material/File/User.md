# Cấu trúc file user

Nằm trong [Nhà chính](../../Introduce.md) > [Material](../../Material.md) > User.dat

## Tổng quan

Đây là file chứa thông tin người chơi.

## Cấu trúc file

Cấu trúc file như sau:

```cpp
    short Nowtheme, short Nowlanguage
    string EncryptScore
```

## Tham số

Hai dòng đầu tiên bao gồm 2 tham số:

- `Nowtheme`
  - Kiểu `short`
  - Giao diện hiện tại.

- `Nowlanguage`
  - Kiểu `short`
  - Ngôn ngữ hiện tại.

Dòng thứ hai là một chuỗi gồm 144 ký tự, cứ mỗi 3 ký tự lại là mã hóa điểm của một màn chơi.
