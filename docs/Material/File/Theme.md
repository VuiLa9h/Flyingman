# Cấu trúc file theme

Nằm trong [Nhà chính](../../Introduce.md) > [Material](../../Material.md) > Theme.dat

## Tổng quan

Đây là file chứa thông tin màu sắc của những phong cách khác nhau.

## Cấu trúc file

File bao gồm nhiều đoạn, tương ứng với những phong cách khác nhau.

Đây là cấu trúc của mỗi đoạn:

```cpp
    string StyleNameVi
    string StyleNameEn
    short BackgroundColor(R), short BackgroundColor(G), short BackgroundColor(B)
    short MainTextColor(R), short MainTextColor(G), short MainTextColor(B)
    short SecondTextColor(R), short SecondTextColor(G), short SecondTextColor(B)
    short ThirdTextColor(R), short ThirdTextColor(G), short ThirdTextColor(B)
    short DisableColor(R), short DisableColor(G), short DisableColor(B)
```

## Tham số

Hai dòng đầu tiên bao gồm 2 tham số:

- `StyleNameVi`
  - Kiểu `string`
  - Tên của phong cách bằng tiếng Việt (tất nhiên rồi).

- `StyleNameEn`
  - Kiểu `string`
  - Tên của phong cách bằng tiếng Anh.

4 dòng tiếp theo quy định màu, mỗi dòng có ba tham số kiểu `short` quy định màu theo hệ RGB.
