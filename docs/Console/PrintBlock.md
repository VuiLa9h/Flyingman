# **PrintBlock**

Hàm này có tác dụng in DẤU CÁCH cho một khối ký tự có kích thước cho trước, bắt nguồn từ một vị trí cho trước, với một màu cho trước.

## Ý tưởng

Làm gì đó

## Code đầy đủ

```cpp
void PrintBlock(short width, short height, short x, short y, short color)
{
    DWORD Garbage; //Thung rac thoi, khong can de y

    color *= 16; //Bien mau chinh thanh mau nen

    for (short i = 0; i < height; i++)
    {
        //Ham nay se in ra ky tu ' ' width lan, bat dau tu vi tri da chon.
        //Sau do ghi so ki tu thuc su duoc in vao bien Garbage.
        FillConsoleOutputCharacter(hConsoleOutput, ' ', width, {(short)x, (short)(y + i)}, &Garbage);
        //Con ham nay dung de to 1 mau duy nhat cho may ky tu do
        FillConsoleOutputAttribute(hConsoleOutput, color, width, {(short)x, (short)(y + i)}, &Garbage);
    }
}
```

## Tham số

- `width`
  - Kiểu `short`
  - Số cột của mảng, tính theo số ký tự.

- `height`
  - Kiểu `short`
  - Số dòng của mảng, cũng tính theo số ký tự.

- `x`
  - Kiểu `short`
  - Hoành độ của vị trí bắt đầu, tính từ 0.

- `y`
  - Kiểu `short`
  - Tung độ của vị trí bắt đầu, tính từ 0.

- `color`
  - Kiểu `short`
  - Màu.

## Những thứ khác

- `Garbage`
  - Kiểu `DWORD`
  - Thùng rác thôi, không cần quan tâm.

## Lưu ý

Mỗi hàm in thường có 2 dạng, `WriteOutputA` và `WriteOutputW`, vậy nó khác nhau ở đâu?  
Nó chỉ khác nhau ở chỗ A dùng kiểu `WORD` - chữ thông thường còn W dùng kiểu `DWORD` - hỗ trợ thêm các chữ tiếng Việt,  tiếng Nhật v.v...  
Mặc định nếu mình không ghi gì thì nó sẽ ngầm hiểu là W.

## Lan quyên

Cũng không có gì nốt.
