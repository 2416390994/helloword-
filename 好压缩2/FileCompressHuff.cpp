#include"FileCompressHuff.hpp"  

#include"LZ77.h"
#include<time.h>
void ZIP(LZ77& LZ,FileCompressHuff& p)
{
	LZ.CompressFile("��Ƶ1.mp4");
	p.CompressFile("2.txt");
}
void UNZIP(LZ77& LZ, FileCompressHuff& p)
{
	p.UNCompressFile("3.txt");
	LZ.UNCompressFile("4.txt","��Ƶ2.mp4");
}
int main()
{
	clock_t begin, end;
	begin = clock();
	LZ77 LZ;
	FileCompressHuff p;
	ZIP(LZ,p);  //ѹ������ʹ��LZ77��ʹ�ù�����
	UNZIP(LZ, p); //��ѹ������ʹ�ù�������ʹ��LZ77
	end = clock();
	cout << "ʹ��ʱ�䣺" << end - begin << endl;
	return 0;
}

















