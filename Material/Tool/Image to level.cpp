#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#define BMP_IN "Level.bmp"
#define TXT_OUT "Level.txt"
#define BMP_OUT "Level_modified.bmp"

#pragma pack(push, 1)
struct Pix
{
	unsigned char B;
	unsigned char G;
	unsigned char R;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BitMap
{
	short m_signature;
	long m_reserved1;
	long m_reserved2;

	long m_dataOffSet;

	long m_size;
	long m_width;
	long m_height;
	short m_planes;
	short m_bpp;

	long m_compression;
	long m_sizeImage;

	long m_xPixelsPreMeter;
	long m_yPixelsPreMeter;

	long m_colorsUsed;
	long m_colorsImportant;
};
#pragma pack(pop)

short BlockNum = 0;
short HoleNum = 0;
bool isHole = false;
struct LevelPack
{
	short xMan, yMan;
	short xDes, yDes;

	short xBlock[200], yBlock[200];
	short xHole[2], yHole[2];
} Level;

void readBMP(const char *filePath, BitMap &header, char *&data);
void WriteTXT();

Pix *convertDataToTxt(char *&data, BitMap &header);

int main(int argc, char **argv)
{
	BitMap _header;
	char *_data = NULL;

	readBMP(BMP_IN, _header, _data);

	Pix *_pixels = convertDataToTxt(_data, _header);
	WriteTXT();
	delete[] _data;
	return 0;
}

void readBMP(const char *filePath, BitMap &header, char *&data)
{
	FILE *f = fopen(filePath, "rb");
	if (!f)
	{
		printf("Cannot open file for reading!!!");
		exit(-1);
	}

	fread(&header, sizeof(header), 1, f);

	int _padding = header.m_width % 4;
	int _size = header.m_width * header.m_height * (header.m_bpp / 8) + _padding * header.m_height;

	data = new char[_size];
	fread(data, sizeof(char), _size, f);

	fclose(f);
}

void WriteTXT()
{
	std::fstream leveldata;
	leveldata.open(TXT_OUT, std::ios_base::out | std::ios_base::trunc); //Ghi de

	leveldata << "1 " << BlockNum << " ";
	if (isHole)
		leveldata << "1 0\n";
	else
		leveldata << "0 0\n";
	leveldata << Level.xMan << " " << Level.yMan << " ";
	leveldata << Level.xDes << " " << Level.yDes << std::endl;
	for (int i = 0; i < BlockNum; i++)
		leveldata << Level.xBlock[i] << " " << Level.yBlock[i] << " ";
	leveldata << std::endl;
	if (isHole)
		leveldata << Level.xHole[0] << " " << Level.yHole[0] << " " << Level.xHole[1] << " " << Level.yHole[1] << std::endl;
	leveldata << std::endl;

	leveldata.close();
}

Pix *convertDataToTxt(char *&data, BitMap &header)
{
	int _size = header.m_width * header.m_height;
	Pix *_pixels = new Pix[_size];

	int _padding = header.m_width % 4;

	char *_temp = data;

	for (int i = 0; i < header.m_height; i++)
	{
		for (int j = 0; j < header.m_width; j++)
		{
			_pixels[i * header.m_height + j].B = *(_temp++);
			_pixels[i * header.m_height + j].G = *(_temp++);
			_pixels[i * header.m_height + j].R = *(_temp++);

			if (_pixels[i * header.m_height + j].R == 255 && _pixels[i * header.m_height + j].G == 255 && _pixels[i * header.m_height + j].B == 255) //Gach
			{
				Level.xBlock[BlockNum] = j;
				Level.yBlock[BlockNum] = 39 - i;
				BlockNum++;
			}
			else if (_pixels[i * header.m_height + j].R == 255 && _pixels[i * header.m_height + j].G == 242 && _pixels[i * header.m_height + j].B == 0) //Lo hong
			{
				Level.xHole[HoleNum] = j;
				Level.yHole[HoleNum] = 39 - i;
				HoleNum++;
				isHole = true;
			}
			else if (_pixels[i * header.m_height + j].R == 0 && _pixels[i * header.m_height + j].G == 162 && _pixels[i * header.m_height + j].B == 232) //Sieu nhan
			{
				Level.xMan = j;
				Level.yMan = 39 - i;
			}
			else if (_pixels[i * header.m_height + j].R == 237 && _pixels[i * header.m_height + j].G == 28 && _pixels[i * header.m_height + j].B == 36) //Dich
			{
				Level.xDes = j;
				Level.yDes = 39 - i;
			}
		}

		_temp += _padding;
	}

	return _pixels;
}