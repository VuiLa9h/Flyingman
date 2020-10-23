# **MoveMan**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
COORD MoveMan(COORD pos, int Key, short levelnumber)
{
    //Dieu huong
    COORD Direction;
    if (Key == _UP_KEY)
        Direction = {0, -1}; //x, y - 1
    else if (Key == _DOWN_KEY)
        Direction = {0, 1}; //x, y + 1
    else if (Key == _LEFT_KEY)
        Direction = {-1, 0}; //x - 1, y
    else if (Key == _RIGHT_KEY)
        Direction = {1, 0}; //x + 1, y

    //Bay den khi nao dam nhau thi thoi;
    while (true)
    {
        COORD Newpos = {(short)(pos.X + Direction.X), (short)(pos.Y + Direction.Y)};

        if (Newpos.X < 0 || Newpos.X > 49 || Newpos.Y < 3 || Newpos.Y > 39) //Ra ngoai chuong ga
        {
            return {0, 0};
        }
        else if (StatusLevel[Newpos.Y][Newpos.X] == 1) //Cuc gach
        {
            if (!Level[levelnumber].isSpecial) //Man binh thuong
                return pos;
            else
            {
                StatusLevel[Newpos.Y][Newpos.X] = 0; //Bien thanh binh thuong

                Gotoxy(2 * Newpos.X, Newpos.Y);
                std::cout << "  ";

                return pos;
            }
        }

        else if (StatusLevel[Newpos.Y][Newpos.X] == 2) //Lo hong
        {
            if (Level[levelnumber].Hole[0].X == Newpos.X && Level[levelnumber].Hole[0].Y == Newpos.Y)
            {
                Newpos.X = Level[levelnumber].Hole[1].X + Direction.X;
                Newpos.Y = Level[levelnumber].Hole[1].Y + Direction.Y;
            }
            else
            {
                Newpos.X = Level[levelnumber].Hole[0].X + Direction.X;
                Newpos.Y = Level[levelnumber].Hole[0].Y + Direction.Y;
            }

            Gotoxy(2 * pos.X, pos.Y);
            std::cout << "  ";
            pos = Newpos;
            Gotoxy(2 * pos.X, pos.Y);
            std::cout << "><";
        }
        else if (StatusLevel[Newpos.Y][Newpos.X] == 3) //Dich
        {
            Gotoxy(2 * pos.X, pos.Y);
            std::cout << "  ";
            return Newpos;
        }
        else //Khong gian
        {
            Gotoxy(2 * pos.X, pos.Y);
            std::cout << "  ";

            pos = Newpos;

            Gotoxy(2 * pos.X, pos.Y);
            std::cout << "><";
        }
        Sleep(20);
        //De phong an linh tinh trong luc choi
        if (_kbhit())
            GetKeyButton();
    }
}
```

## Tham số

- `pos`
  - Kiểu `COORD`
  - Làm gì đó.

- `Key`
  - Kiểu `int`
  - Làm gì đó.

- `levelnumber`
  - Kiểu `int`
  - Làm gì đó.

## Những thứ khác

- `1`
  - Kiểu `int`
  - Làm gì đó.

- `2`
  - Kiểu `int`
  - Làm gì đó.

## Lưu ý

Không có gì.

## Lan quyên

Cũng không có gì nốt.
