# **Phongcachthoitrang**

Hàm này dùng để chỉnh kích thước cửa số, lấy thông tin màu sắc, điểm số, v.v... khi bắt đầu khởi động.

## Ý tưởng

- Đầu tiên là lấy thông tin màu sắc, level, người chơi.

- Đổi màu ghêm cho hợp.

- Vô hiệu hóa việc điều chỉnh kích thước cửa sổ lung tung.

- Ẩn con chuột đi cho đỡ nhấp nháy.

- Chỉnh kích cỡ cửa số và bộ đệm về 100x40.

- Đổi màu chữ thành 1, màu nền thành 0.

## Code đầy đủ

```cpp
void Phongcachthoitrang()
{
    GetUserData();
    GetLanguagePack();
    GetLevelPack();

    GetLogoInfo();
    GetColorPalette();
    ChangeColorPallete(UserNowData.Nowtheme);

    DisableResize();

    ShowCursor(false);
    ResizeScreenBuffer(100, 40);
    ResizeConsole(100, 40);

    system("color 01");
}
```

## Lưu ý

Hàm chỉ dùng một lần duy nhất khi bắt đầu khởi động ghêm.

## Lan quyên

- [GetUserData](../Material/GetUserData.md)

- [GetLanguagePack](../Material/GetLanguagePack.md)

- [GetLevelPack](../Material/GetLevelPack.md)

- [GetLogoInfo](../Material/GetLogoInfo.md)

- [GetColorPalette](../Material/GetColorPalette.md)

- [ChangeColorPallete](../Console/ChangeColorPallete.md)

- [DisableResize](../Console/DisableResize.md)

- [ShowCursor](../Console/ShowCursor.md)

- [ResizeScreenBuffer](../Console/ResizeScreenBuffer.md)

- [ResizeConsole](../Console/ResizeConsole.md)
