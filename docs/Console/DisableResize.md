# **DisableResize**

Hàm này có tác dụng vô hiệu hóa việc thay đổi kích cỡ cửa sổ, tránh người chơi chỉnh lung tung.

## Ý tưởng

Lấy thông tin cửa cửa số, tắt một số thuộc tính đi rồi xóa menu đi.

## Code đầy đủ

```cpp
void DisableResize()
{
    SetConsoleTitle(TEXT("Flying Man"));
    Sleep(50); //Let the window to update the title!

    hConsole = FindWindow(NULL, TEXT("Flying Man")); //Find this console.
    //Neukhong co lenh sleep thi khong the tim duoc cua so nay

    HMENU hMenu = GetSystemMenu((HWND)hConsole, FALSE);

    mii.fState = MFS_GRAYED;
    EnableMenuItem(hMenu, 4, MF_DISABLED);
    SetMenuItemInfo(hMenu, 4, MF_BYPOSITION, &mii);

    DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Move'
    DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Size'
    DeleteMenu(hMenu, 2, MF_BYPOSITION); // disable 'Maximize'
}
```

## Tham số

Không có gì.

## Những thứ khác

Không có gì.

## Lưu ý

Tui thêm `SetConsoleTitle` vào đây cho code nó ngắn gọn, mặc dù hai việc này không liên quan gì đến nhau.

## Lan quyên

Cũng không có gì nốt.
