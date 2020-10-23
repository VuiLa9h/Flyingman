# **GetLogoInfo**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetLogoInfo

Hàm này có tác dụng chuyển thông tin từ `LogoInfor` sang `LogoInfoColor`.

## Ý tưởng

Vì chúng ta bôi màu vào các ký tự `▄` nên cái nào ở trên sẽ là màu nền, cái nào ở dưới sẽ là màu chính.

## Code đầy đủ

```cpp
void GetLogoInfo()
{
    //Nhap mau cho logo be
    for (short i = 0; i < 4; i++)
    {
        for (short j = 0; j < 34; j++)
        {
            //Neu la ' ' thi ra 0, con lai ra chinh no
            short backgroundcolor = 0 * (LogoInfo[2 * i][j] == ' ') + (LogoInfo[2 * i][j] != ' ') * (LogoInfo[2 * i][j] - '0' + 12);
            short foregroundcolor = 0 * (LogoInfo[2 * i + 1][j] == ' ') + (LogoInfo[2 * i + 1][j] != ' ') * (LogoInfo[2 * i + 1][j] - '0' + 12);
            LogoInfoColor[i][j] = 16 * backgroundcolor + foregroundcolor;
        }
    }
}
```

## Lưu ý

Hàm này chỉ dùng 1 lần duy nhất.

## Lan quyên

[LogoInfo và LogoInfoColor](../Material.md#LogoInfo%20và%20LogoInfoColor)
