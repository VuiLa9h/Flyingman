# **GetTextRaw**

Nằm trong [Nhà chính](../Introduce.md) > [Material](../Material.md) > GetTextRaw

Hàm này có tác dụng lấy thông tin loại thô từ file `Story.dat`.

## Ý tưởng

Nhập màu vào mảng `TextRawColor`, sau đó nhập các đoạn chữ vào mảng `TextRaw`.

## Code đầy đủ

```cpp
short GetTextRaw()
{
    std::string nowpath = materialpath + (std::string) "Story" + Language[UserNowData.Nowlanguage].Label + (std::string) ".dat";
    int count = 0;

    std::ifstream textraw(nowpath);
    while (!textraw.eof())
    {
        textraw >> TextRawColor[count];
        std::getline(textraw, TextRaw[count]);
        count++;
    }
    textraw.close();

    return count;
}
```

## Lưu ý

Hàm trả về `count`, là số đoạn chữ của file.

## Lan quyên

[TextRaw và TextRawColor](../Material.md#TextRaw%20và%20TextRawColor)
