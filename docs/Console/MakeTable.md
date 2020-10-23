# **MakeTable**

Hàm này có tác dụng tao ra một bảng nhiều ô vuông như ta mong muốn, tại vị trí (x, y) trên màn hình.

## Ý tưởng

Làm theo 4 bước sau:

- Bước 1: In hàng ngang.
  - In viền ngang bằng ký tự `═`.
  - In đường kẻ ngang bằng ký tự `─`.

- Bước 2: In hàng dọc.
  - In viền dọc bằng ký tự `║`.
  - In đường kẻ ngang bằng ký tự `|`.

- Bước 3: In 4 cái góc.
  - Dùng các ký tự `╔`, `╗`, `╚` và `╝`.

- Bước 4: In các giao điểm giữa cạnh bảng và các ô.
  - Dùng các ký tự `╦`, `╩`, `╠` và `╣`.

- Bước 5: In giao điểm của các ô vuông với nhau.
  - Dùng ký tự `+`.

## Code đầy đủ

```cpp
void MakeTable(short row, short column, short x, short y)
{
    //Kiem tra dieu kien
    if ((row <= 0) || (column <= 0))
        return;

    DWORD Garbage; //Thung rac thoi, khong can de y

    //Hang ngang
    {
        FillConsoleOutputCharacter(hConsoleOutput, (char)205, 4 * column + 1, {x, y}, &Garbage);
        FillConsoleOutputCharacter(hConsoleOutput, (char)205, 4 * column + 1, {x, (short)(y + 2 * row)}, &Garbage);
        for (short i = 1; i < row; i++)
            FillConsoleOutputCharacter(hConsoleOutput, (char)196, 4 * column + 1, {x, (short)(y + 2 * i)}, &Garbage);
    }

    //Cot doc
    {
        for (short i = 0; i < row; i++)
        {
            Gotoxy(x, y + 1 + 2 * i);
            std::cout << (char)186;
            Gotoxy(x + 4 * column, y + 1 + 2 * i);
            std::cout << (char)186;
        }
        for (short i = 1; i < column; i++)
        {
            for (short j = 0; j < row; j++)
            {
                Gotoxy(x + 4 * i, y + 1 + 2 * j);
                std::cout << '|';
            }
        }
    }

    //Goc
    {
        Gotoxy(x, y);
        std::cout << (char)201;
        Gotoxy(x, y + 2 * row);
        std::cout << (char)200;
        Gotoxy(x + 4 * column, y);
        std::cout << (char)187;
        Gotoxy(x + 4 * column, y + 2 * row);
        std::cout << (char)188;
    }

    //Canh
    {
        for (short i = 1; i < row; i++) //Canh doc
        {
            Gotoxy(x, y + 2 * i);
            std::cout << (char)204;
            Gotoxy(x + 4 * column, y + 2 * i);
            std::cout << (char)185;
        }
        for (short i = 1; i < column; i++) //Canh ngang
        {
            Gotoxy(x + 4 * i, y);
            std::cout << (char)203;
            Gotoxy(x + 4 * i, y + 2 * row);
            std::cout << (char)202;
        }
    }

    //Giao diem
    for (short i = 1; i < column; i++)
    {
        for (short j = 1; j < row; j++)
        {
            Gotoxy(x + 4 * i, y + 2 * j);
            std::cout << (char)197;
        }
    }
}
```

## Tham số

- `row`
  - Kiểu `short`
  - Số dòg của bảng.

- `column`
  - Kiểu `short`
  - Số cột của bảng.

- `x`
  - Kiểu `short`
  - Hoành độ của bảng, tính từ 0.

- `y`
  - Kiểu `short`
  - Tung độ của bảng, tính từ 0.

## Những thứ khác

Không có gì.

## Lưu ý

Hàm này chả được dùng bao giờ, vốn dĩ nó là hàm dựng bảng của ghêm dò mìn cơ.

## Lan quyên

Cũng không có gì nốt.
