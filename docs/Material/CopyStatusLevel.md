# **CopyStatusLevel**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > CopyStatusLevel

Hàm này có tác dụng sao chép trạng thái của level gốc vào màn chơi mới.

## Ý tưởng

Sao chép trạng thái của level gốc (được lưu trong `Level[levelnumber].SpaceStatus`) vào `StatusLevel`.

## Code đầy đủ

```cpp
void CopyStatusLevel(short levelnumber)
{
    for (short i = 0; i < 40; i++)
        for (short j = 0; j < 50; j++)
            StatusLevel[i][j] = Level[levelnumber].SpaceStatus[i][j];
}
```

## Tham số

- `levelnumber`
  - Kiểu `short`
  - Level hiện tại (tính từ 1).

## Lan quyên

- [Level](../Material.md#Level)
- [StatusLevel](../Material.md#StatusLevel)
- [GetLevelPack](GetLevelPack.md)
