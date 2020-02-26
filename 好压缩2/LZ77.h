#pragma once
#include<string>
#include "LZHashTable.h"


class LZ77
{
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string& strFilePath);
	void UNCompressFile(const std::string& strFilePath, const std::string& strFilePath2);
private:
	USH LongestMatch(USH matchHead, USH& curMatchDist, USH start);
	void WriteFlags(FILE* fouts, UCH& chFalg, UCH& bitCount, bool isCharorLen);
	void MergeFile(FILE* fout, ULL filesize);
	void FillWindow(FILE* fIn, size_t& lookAhead,USH& start);
 
private:
	UCH* pWin;   //用来保存待压缩数据的缓冲区
	LZHashTable ht;
};
























