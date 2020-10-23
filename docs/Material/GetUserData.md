# **GetUserData**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetUserData

Hàm này có tác dụng lấy thông tin người chơi từ file `User.dat`.

## Ý tưởng

Nhập thông tin theo đúng cấu trúc của file `User.dat` ở [đây](./File/User.md). Sau đó chuyển điểm đã được mã hóa thành điểm dưới dạng số và gán vào `UserNowData.EncryptScore`.

## Code đầy đủ

```cpp
void GetUserData()
{
    std::string nowpath = materialpath + (std::string) "User.dat";
    std::string Garbage; //Thung rac thoi, khong can quan tam

    std::fstream data;
    data.open(nowpath, std::ios_base::in);
    while (!data.eof())
    {
        data >> UserNowData.Nowtheme;
        data >> UserNowData.Nowlanguage;
        std::getline(data, Garbage);
        std::getline(data, UserNowData.EncryptScore);
    }
    data.close();

    //Nhap diem
    for (int i = 0; i < 49; i++)
    {
        UserNowData.HighScore[i] = (UserNowData.EncryptScore[3 * i] - 'a') * 26 * 26;
        UserNowData.HighScore[i] += (UserNowData.EncryptScore[3 * i + 1] - 'a') * 26;
        UserNowData.HighScore[i] += (UserNowData.EncryptScore[3 * i + 2] - 'a');
    }
}
```

## Lan quyên

- [User](File/User.md)
- [UserNowData](../Material.md#UserNowData)
- [SetUserData](SetUserData.md)
