#pragma once
#include "Common.h"

const USH HASH_BITS = 15;
const USH HASH_SIZE = (1 << HASH_BITS);
const USH HASH_MASK = HASH_SIZE - 1;


class LZHashTable
{
public:
	LZHashTable(USH size);
	~LZHashTable();
	void Insert(USH& hashAddr, UCH ch, USH pos, USH& macthHead);
	void HashFunc(USH& hashAddr, UCH ch);
	USH GetNext(USH matchHead);
	void update();

private:  
	USH H_SHIFT();

private:
	//用prev和head合在一起表示一个完整的具有一定解决哈希冲突能力的哈希表
	USH* prev;  //类似于存储位置的链表
	USH* head;  //哈希表的开始位置
};





