#include"FileCompressHuff.hpp"  

#include"LZ77.h"
#include<time.h>
void ZIP(LZ77& LZ,FileCompressHuff& p)
{
	LZ.CompressFile("视频1.mp4");
	p.CompressFile("2.txt");
}
void UNZIP(LZ77& LZ, FileCompressHuff& p)
{
	p.UNCompressFile("3.txt");
	LZ.UNCompressFile("4.txt","视频2.mp4");
}
int main()
{
	clock_t begin, end;
	begin = clock();
	LZ77 LZ;
	FileCompressHuff p;
	ZIP(LZ,p);  //压缩，先使用LZ77再使用哈夫曼
	UNZIP(LZ, p); //解压缩，先使用哈夫曼再使用LZ77
	end = clock();
	cout << "使用时间：" << end - begin << endl;
	return 0;
}

















