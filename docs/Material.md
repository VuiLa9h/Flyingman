# **Material**

Nằm trong [Nhà chính](Introduce.md) > Material

Đây là nơi chứa tất cả những gì bạn cần về các hàm trong Material.

## **Mục lục**

- [Những giá trị cần biết](#Những%20giá%20trị%20cần%20biết)
  - [MyColorPalette](#MyColorPalette)
  - [Language](#Language)
  - [Level](#Level)
  - [UserNowData](#UserNowData)
  - [StatusLevel](#StatusLevel)
  - [AuthorList](#AuthorList)
  - [NumberInfo](#NumberInfo)
  - [LogoInfo và LogoInfoColor](#LogoInfo%20và%20LogoInfoColor)
  - [TextRaw và TextRawColor](#TextRaw%20và%20TextRawColor)
- [CopyStatusLevel](#CopyStatusLevel)
- [GetColorPalette](#GetColorPalette)
- [GetLanguagePack](#GetLanguagePack)
- [GetLevelPack](#GetLevelPack)
- [GetLogoInfo](#GetLogoInfo)
- [GetTextRaw](#GetTextRaw)
- [GetUserData](#GetUserData)
- [SetUserData](#SetUserData)

---

## **Những giá trị cần biết**

Trước khi vào bài, chúng ta cần biết những giá trị sau:

### **MyColorPalette**

- Kiểu: `StyleInfo`
- Được khai báo như sau:

```cpp
struct StyleInfo
{
    std::string StyleName[2];
    COLORREF BackgroundColor;
    COLORREF MainTextColor;
    COLORREF SecondTextColor;
    COLORREF ThirdTextColor;
    COLORREF DisableColor;
};

extern StyleInfo MyColorPalette[10];
```

**Ý nghĩa**: Chứa thông tin của chủ đề, bao gồm tên, màu nền, màu chính, màu 2, màu 3, màu chưa chọn.

### **Language**

- Kiểu: `LanguagePack`
- Được khai báo như sau:

```cpp
struct LanguagePack
{
    std::string Label;
    std::string MenuList[5];
    std::string LevelList[3];
    std::string PlayList[10];
    std::string StoryList[2];
    std::string OptionList[5];
    std::string CreditList[20];
};

extern LanguagePack Language[2];
```

**Ý nghĩa**: Chứa các dòng chữ trong trò chơi, bao gồm cả Tiếng Việt lẫn Tiếng Anh, trong đó:

- `Label`: Nhãn.
- `MenuList`: Các dòng trong menu chính.
- `LevelList`: Các dòng trong trang chọn level.
- `PlayList`: Các dòng trong trang chơi chính.
- `StoryList`: Các dòng trong trang câu chuyện và hướng dẫn.
- `OptionList`: Các dòng trong trang cài đặt.
- `CreditList`: Các dòng trong trang ghi công.

### **Level**

- Kiểu: `LevelPack`
- Được khai báo như sau:

```cpp
struct LevelPack
{
    short Rate;
    short BlockNum;
    bool isHole;
    bool isSpecial;

    COORD Man;
    COORD Des;

    COORD Block[200];
    COORD Hole[2];
    short SpaceStatus[40][100];
};

extern LevelPack Level[50];
```

**Ý nghĩa**: Chứa thông tin của các màn chơi, bao gồm:

- `Rate`
  - Kiểu `short`
  - Độ khó của màn chơi.

- `BlockNum`
  - Kiểu `short`
  - Số cục gạch của màn chơi.

- `isHole`
  - Kiểu `bool`
  - Xác định xem màn chơi đó có lỗ hổng không gian hay không.

- `isSpecial`
  - Kiểu `bool`
  - Xác định xem đó có phải màn chơi đặc biệt hay không (màn chơi đặc biệt là màn chơi mà viên gạch sẽ biến mất sau khi Đỗ Rê Mon đâm vào).

- `Man`
  - Kiểu `COORD`
  - Vị trí ban đầu của Đỗ Rê Mon.

- `Des`
  - Kiểu `COORD`
  - Vị trí của đích đến.

- `Block`
  - Kiểu `COORD`
  - Vị trí của viên gạch.

- `Hole`
  - Kiểu `COORD`
  - Vị trí của lỗ hổng không gian (nếu có).

- `SpaceStatus`
  - Kiểu `short`
  - Trạng thái nguyên thủy của màn chơi, lấy từ các biến kể trên, dùng khi chơi ghêm.

### **UserNowData**

- Kiểu: `UserData`
- Được khai báo như sau:

```cpp
struct UserData
{
    short Nowtheme;
    short Nowlanguage;
    std::string EncryptScore;
    int HighScore[50];
};

extern UserData UserNowData;
```

**Ý nghĩa**: Chứa thông tin người chơi, bao gồm giao diện, ngôn ngữ, điểm (mã hóa và không mã hóa).

### **StatusLevel**

- Kiểu: `Short`
- Được khai báo như sau:

```cpp
extern short StatusLevel[40][50];
```

**Ý nghĩa**: Trạng thái của level, được dùng khi đang chơi. Nó bao gồm 4 giá trị là `0`, `1`, `2` và `3`. Trong đó:

- `0`: Trống rỗng, không có gì.
- `1`: Hòn đá, cục gạch.
- `2`: Lỗ hổng không gian.
- `3`: Đích.

### **AuthorList**

- Kiểu: `string`
- Được khai báo như sau:

```cpp
//Material.hpp
extern std::string AuthorList[12];

//Material.cpp
std::string AuthorList[12] = {
    "Vtysvt",
    "Giang Van Minh",
    "Doremon Viet Nam",
    "Light Bro Animation",
    "Chau Bui",
    "Nguyen Minh Long",
    "Light Bro Animation",
    "Le Nguyen Duong",
    "Pham Hanoi",
    "Chau Bui",
    "Man Chin Rung, Pham Hanoi",
    "Crazyrabvn",
};
```

**Ý nghĩa**: Thông tin của nhà phát hành, các nhân sự tham gia.

### **NumberInfo**

- Kiểu: `char`
- Được khai báo như sau:

```cpp
//Material.hpp
extern char NumberInfo[6][32];

//Material.cpp
char NumberInfo[6][32] = {
//  &000111222333444555666777888999
    "111 1 1111111  111111111111111",
    "1 111   1  11 11  1    11 11 1",
    "1 1 1 111 11111111111 11111111",
    "1 1 1 1    1  1  11 1  11 1  1",
    "111111111111  1111111  1111111",
    "                              ",
};
```

**Ý nghĩa**: Thông tin theo định dạng bitmap của số. Trong đó mỗi 3 cột 5 hàng lại biểu thị một số, với `1` là có điểm ảnh và `0` là không có điểm ảnh.

### **LogoInfo và LogoInfoColor**

- Kiểu: `char`, `WORD`
- Được khai báo như sau:

```cpp
//Material.hpp
extern char LogoInfo[8][40];
extern WORD LogoInfoColor[5][35];

//Material.cpp
char LogoInfo[8][40] = {

    "111 2 3333333333333  1   1 3333333",
    "1   2                11 11        ",
    "11  2 2   2  22 22   1 1 1  2   22",
    "1   2 2 2 2 2 2 2 2  1   1 222 2 2",
    "1   2 222 2 2 2 222  1   1 2 2 2 2",
    "        2         2  1            ",
    "222222222 222222222  1111111111111",
    "                                  ",
};
WORD LogoInfoColor[5][35];
```

**Ý nghĩa**:

- `LogoInfo` chứa thông tin theo định dạng bitmap của logo, với `0` là không có điểm ảnh, `1` là màu xanh (mã màu 13), `2` là màu đỏ (mã màu 14) và `3` là màu vàng (mã màu 15).
- `LogoInfoColor` là ánh xạ của `LogoInfo` nhưng được viết dưới dạng `WORD` để có thể dùng được.

### **TextRaw và TextRawColor**

- Kiểu: `string`, `short`
- Được khai báo như sau:

```cpp
extern std::string TextRaw[500];
extern short TextRawColor[500];
```

**Ý nghĩa**:

- `TextRaw` chứa thông tin các đoạn chữ trong file câu chuyện.
- `TextRawColor` lưu trữ màu của đoạn chữ tương ứng.

---

## **CopyStatusLevel**

Bài chi tiết: [CopyStatusLevel](Material/CopyStatusLevel.md)

Hàm này có tác dụng sao chép trạng thái của level gốc vào màn chơi mới.

Cú pháp của hàm `CopyStatusLevel` như sau:

```cpp
void CopyStatusLevel(short levelnumber);
```

Tham số:

- `levelnumber`
  - Kiểu `short`
  - Level hiện tại (tính từ 1).

---

## **GetColorPalette**

Bài chi tiết: [GetColorPalette](Material/GetColorPalette.md)

Hàm này có tác dụng lấy bảng màu cho giao diện ghêm, được lưu trữ trong file `Theme.dat`.

Cú pháp của hàm `GetColorPalette` như sau:

```cpp
void GetColorPalette();
```

---

## **GetLanguagePack**

Bài chi tiết: [GetLanguagePack](Material/GetLanguagePack.md)

Hàm này có tác dụng khởi tạo thông tin ban đầu về các dòng chữ trong ghêm, với `0` là Tiếng Việt và `1` là Tiếng Anh.

Cú pháp của hàm `GetLanguagePack` như sau:

```cpp
void GetLanguagePack();
```

---

## **GetLevelPack**

Bài chi tiết: [GetLevelPack](Material/GetLevelPack.md)

Hàm này có tác dụng lấy thông tin của 49 màn chơi trong ghêm (màn 0 là màn đặc biệt).

Cú pháp của hàm `GetLevelPack` như sau:

```cpp
void GetLevelPack();
```

---

## **GetLogoInfo**

Bài chi tiết: [GetLogoInfo](Material/GetLogoInfo.md)

Hàm này có tác dụng chuyển thông tin từ `LogoInfor` sang `LogoInfoColor`.

Cú pháp của hàm `GetLogoInfo` như sau:

```cpp
void GetLogoInfo();
```

---

## **GetTextRaw**

Bài chi tiết: [GetTextRaw](Material/GetTextRaw.md)

Hàm này có tác dụng lấy thông tin loại thô từ file `Story.dat`.

Cú pháp của hàm `GetTextRaw` như sau:

```cpp
short GetTextRaw();
```

---

## **GetUserData**

Bài chi tiết: [GetUserData](Material/GetUserData.md)

Hàm này có tác dụng lấy thông tin người chơi từ file `User.dat`.

Cú pháp của hàm `GetUserData` như sau:

```cpp
void GetUserData();
```

---

## **SetUserData**

Bài chi tiết: [SetUserData](Material/SetUserData.md)

Hàm này có tác dụng ghi thông tin người chơi vào file `User.dat`.

Cú pháp của hàm `SetUserData` như sau:

```cpp
void SetUserData();
```
