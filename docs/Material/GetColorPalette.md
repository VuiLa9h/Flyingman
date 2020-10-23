# **GetColorPalette**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetColorPalette

Hàm này có tác dụng lấy bảng màu cho giao diện ghêm, được lưu trữ trong file `Theme.dat`.

## Ý tưởng

Nhập các giá trị theo đúng cấu trúc của `Theme.dat`. Chi tiết xem tại [đây](./File/Theme.md).

## Code đầy đủ

```cpp
void GetColorPalette()
{
    std::string nowpath = materialpath + (std::string) "Theme.dat";
    short count = 0;
    short R, G, B;
    std::string Garbage; //Thung rac thoi, khong can quan tam.

    std::ifstream theme(nowpath);
    while (!theme.eof())
    {
        std::getline(theme, Garbage); //Tai sao lai co dong nay? Hay doc (*)

        std::getline(theme, MyColorPalette[count].StyleName[0]);
        std::getline(theme, MyColorPalette[count].StyleName[1]);

        theme >> R >> G >> B;
        MyColorPalette[count].BackgroundColor = RGB(R, G, B);
        theme >> R >> G >> B;
        MyColorPalette[count].MainTextColor = RGB(R, G, B);
        theme >> R >> G >> B;
        MyColorPalette[count].SecondTextColor = RGB(R, G, B);
        theme >> R >> G >> B;
        MyColorPalette[count].ThirdTextColor = RGB(R, G, B);
        theme >> R >> G >> B;
        MyColorPalette[count].DisableColor = RGB(R, G, B);

        count++;
    }
    theme.close();
}
```

## Những thứ khác

- `count`
  - Kiểu `short`
  - Đếm số giao diện được nhập vào.

- `R`, `G`, `B`
  - Kiểu `short`
  - RGB.

- `Garbage`
  - Kiểu `string`
  - Thùng rác thôi, không cần quan tâm.

## Lưu ý

- Hàm getline() đọc dữ liệu đến khi gặp dấu xuống dòng thì thôi.
- Từ vị trí cuối của lần lặp trước (`B` của `DisableColor`), con trỏ vẫn đang mắc kẹt ở dòng `DisableColor`.
- Do đó ta phải dùng một biến là `Garbage` để vứt dấu `\0` thừa đi. Rồi sau đó mới nhập tiếp dòng `NameVi`.

## Lan quyên

- [Theme](File/Theme.md)
- [MyColorPalette](../Material.md#MyColorPalette)
