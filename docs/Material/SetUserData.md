# **SetUserData**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > SetUserData

Hàm này có tác dụng ghi thông tin người chơi vào file `User.dat`.

## Ý tưởng

Ghi đè thông tin, mã hóa điểm và ghi đè tiếp vào file.

## Code đầy đủ

```cpp
void SetUserData()
{
    std::string nowpath = materialpath + (std::string) "User.dat";

    std::fstream data;
    data.open(nowpath, std::ios_base::out | std::ios_base::trunc); //Ghi de
    data << UserNowData.Nowtheme << " " << UserNowData.Nowlanguage << std::endl;
    for (int i = 0; i < 49; i++)
    {
        char c3 = UserNowData.HighScore[i] % 26 + 'a';
        char c2 = (UserNowData.HighScore[i] / 26) % 26 + 'a';
        char c1 = (UserNowData.HighScore[i] / 26 / 26) % 26 + 'a';
        data << c1 << c2 << c3;
    }
    data.close();
}
```

## Lan quyên

- [User](File/User.md)
- [UserNowData](../Material.md#UserNowData)
- [GetUserData](GetUserData.md)
