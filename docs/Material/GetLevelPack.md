# **GetLevelPack**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetLevelPack

Hàm này có tác dụng lấy thông tin của 49 màn chơi trong ghêm (màn 0 là màn đặc biệt).

## Ý tưởng

Nhập thông tin vào dựa trê cấu trúc của file `Level.dat`. Chi tiết xem tại [đây](./File/Level.md).

## Code đầy đủ

```cpp
void GetLevelPack()
{
    std::string nowpath = materialpath + (std::string) "Level.dat";

    std::fstream data;
    data.open(nowpath, std::ios_base::in);
    for (short i = 0; i < 49; i++)
    {
        //Tao moi mang trang thai
        for (short _i = 0; _i < 40; _i++)
            for (short _j = 0; _j < 100; _j++)
                Level[i].SpaceStatus[_i][_j] = 0;

        data >> Level[i].Rate;
        data >> Level[i].BlockNum;
        data >> Level[i].isHole;
        data >> Level[i].isSpecial;

        data >> Level[i].Man.X >> Level[i].Man.Y;
        data >> Level[i].Des.X >> Level[i].Des.Y;
        Level[i].SpaceStatus[Level[i].Des.Y][Level[i].Des.X] = 3;

        for (int j = 0; j < Level[i].BlockNum; j++)
        {
            data >> Level[i].Block[j].X >> Level[i].Block[j].Y;
            Level[i].SpaceStatus[Level[i].Block[j].Y][Level[i].Block[j].X] = 1;
        }

        if (Level[i].isHole)
        {
            data >> Level[i].Hole[0].X >> Level[i].Hole[0].Y;
            data >> Level[i].Hole[1].X >> Level[i].Hole[1].Y;

            Level[i].SpaceStatus[Level[i].Hole[0].Y][Level[i].Hole[0].X] = 2;
            Level[i].SpaceStatus[Level[i].Hole[1].Y][Level[i].Hole[1].X] = 2;
        }
    }
    data.close();
}
```

## Lan quyên

- [Level.dat](File/Level.md)
- [Level](../Material.md#Level)
