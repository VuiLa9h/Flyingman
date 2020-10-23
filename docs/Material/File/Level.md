# Cấu trúc file level

Nằm trong [Nhà chính](../../Introduce.md) > [Material](../../Material.md) > Level.dat

## Tổng quan

Đây là file chứa thông tin của tất cả các màn chơi, bao gồm độ khó, tọa độ, những thứ đặc biệt, ...

## Lưu ý

Tất cả tọa độ ở đây nằm trong vùng 40 x 50, tức là chúng ta phải lấy 2 ký tự mỗi hàng.

## Cấu trúc file

File bao gồm 49 đoạn, tương ứng với 49 màn chơi (48 màn bình thường và 1 màn đặc biệt).

Đây là cấu trúc của mỗi đoạn:

```cpp
short Rate, short BlockNum, bool isHole, bool isSpecial
short xMan, short yMan, short xDes, short yDes
short xBlock[0], short yBlock[0]...
short xHole[0], short yHole[0], short xHole[1], short yHole[1]
```

## Tham số

Dòng đầu tiên bao gồm 4 tham số:

- `Rate`
  - Kiểu `short`
  - Quy định độ khó của màn chơi (nằm từ 1 đến 5).

- `BlockNum`
  - Kiểu `short`
  - Quy định số viên gạch trong màn chơi.

- `isHole`
  - Kiểu `bool`
  - Màn chơi có lỗ hổng hay không?

- `isSpecial`
  - Kiểu `bool`
  - Xác định xem màn chơi này có phải màn chơi đặc biệt hay không.
    - `0` là chế độ thông thường.
    - `1` là chế độ chạm gạch gạch biến mất luôn.

Dòng thứ hai bao gồm 4 tham số:

- `xMan`, `yMan`
  - Kiểu `short`
  - Tọa độ ban đầu của siêu nhân.

- `xDes`, `yDes`
  - Kiểu `short`
  - Tọa độ của đích đến.

Dòng thứ ba bao gồm `BlockNum` cặp số. Mỗi cặp là một tọa độ của viên gạch.

Dòng thứ tư bao gồm `2` cặp số. Mỗi cặp là tọa độ của lỗ hổng (nếu có).
