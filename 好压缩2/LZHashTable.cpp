
#include "LZHashTable.h"
#include<string.h>






LZHashTable::LZHashTable(USH size)
:prev(new USH[size * 2])
, head(prev + size)
{
	memset(prev, 0, size * 2 * sizeof(USH));
}
LZHashTable::~LZHashTable()
{
	delete[] prev;
	prev = nullptr;
}

// hashAddr：上一次哈希地址 ch：先行缓冲区第一个字符 
// pos：ch在滑动窗口中的位置 matchHead：如果匹配，保存匹配串的起始位置
void LZHashTable::Insert(USH& hashAddr, UCH ch, USH pos, USH& macthHead)
{
	// 计算哈希地址 
	HashFunc(hashAddr, ch);
	// 随着压缩的不断进行，pos肯定会大于WSIZE，与上WMASK保证不越界 
	prev[pos & HASH_MASK] = head[hashAddr];
	macthHead = head[hashAddr];
	head[hashAddr] = pos;
}

//用来计算哈希地址的函数
//本次的哈希地址是在上一次哈希地址的基础上计算出来的
void LZHashTable::HashFunc(USH& hashAddr, UCH ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}
USH LZHashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

void LZHashTable::update()
{
	for (USH i = 0; i < WSIZE; ++i)
	{
		//先更新head
		if (head[i] >= WSIZE)
			head[i] -= WSIZE;
		else
			head[i] = 0;
	

		//更新prev
		if (prev[i] >= WSIZE)
			prev[i] -= WSIZE;
		else
			prev[i] = 0;
	}

	
}