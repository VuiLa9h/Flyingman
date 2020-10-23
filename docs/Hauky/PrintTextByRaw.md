# **PrintTextByRaw**

Hàm này có tác dụng...

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
bool PrintTextByRaw(short margin)
{
    short maxWritesize = 100 - 2 * margin;
    int count = GetTextRaw();
    short nowX = 0; //Vi tri cua con chuot hien tai, tinh theo vung viet. (0-maxWritesize)
    short nowY = 0; //Vi tri cua con chuot hien tai, tinh theo vung viet. (0-34)

    for (int j = 0; j < margin; j++) //Can le lan dau
        std::cout << " ";
    for (int i = 0; i < count; i++)
    {
        if (TextRawColor[i] == 0) //Neu bang 0 thi xuong dong, qua ro rang roi
        {
            //Qua kho thi dung lai
            if (nowY + 2 >= 34)
            {
                while (true)
                {
                    int Key = GetKeyButton();

                    if (Key == _ESC_KEY)
                        return false;

                    else if (Key == _TAB_KEY || Key == _SPACE_KEY || Key == _ENTER_KEY)
                    {
                        PrintBlock(maxWritesize, 92, margin, 4, 0);
                        nowX = nowY = 0;

                        Gotoxy(0, 4);
                        for (int j = 0; j < margin; j++) //Can le lan sau
                            std::cout << " ";

                        break;
                    }
                }
            }
            else //Khong thi van cu in nhu thuong
            {
                std::cout << std::endl
                          << std::endl;
                for (int j = 0; j < margin; j++) //Can le
                    std::cout << " ";
                nowX = 0;
                nowY += 2;
            }
        }
        else
        {
            DoiMauChu(TextRawColor[i]);

            int printedchar = 0;						 //So chu cai da in.
            int TextRawLength = TextRaw[i].length() - 1; //So chu can phai in

            while (nowX + TextRawLength - printedchar >= maxWritesize) //Neu so chu vuot qua muc quy dinh thi sao?
            {
                short writelength = maxWritesize - nowX; //So chu se phai ghi tiep theo
                for (int j = printedchar; j < printedchar + writelength; j++)
                    std::cout << TextRaw[i][j + 1];

                if (nowY + 1 >= 34) //Neu qua kho thi sao?
                {
                    while (true)
                    {
                        int Key = GetKeyButton();

                        if (Key == _ESC_KEY)
                            return false;

                        else if (Key == _TAB_KEY || Key == _SPACE_KEY || Key == _ENTER_KEY)
                        {
                            PrintBlock(maxWritesize, 92, margin, 4, 0);
                            nowY = 0;

                            Gotoxy(0, 4);
                            for (int j = 0; j < margin; j++) //Can le lan sau
                                std::cout << " ";

                            break;
                        }
                    }
                }

                else
                {
                    std::cout << std::endl; //Xuong dong la ro
                    for (int j = 0; j < margin; j++)
                        std::cout << " ";

                    nowY++;
                }

                printedchar += writelength;
                nowX = 0;
            }

            if (printedchar == TextRawLength) //Neu da in du roi thi thoi khong in nua
                continue;

            //Neu khong du ta moi phai lam tiep
            for (int j = printedchar; j < TextRawLength; j++) //In phan con lai
                std::cout << TextRaw[i][j + 1];
            nowX = (nowX + TextRawLength + 1 - printedchar);
            std::cout << " "; //Khoang trang cuoi tu.
        }
    }

    return true;
}
```

## Tham số

- `margin`
  - Kiểu `short`
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
