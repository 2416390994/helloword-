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
	//��prev��head����һ���ʾһ�������ľ���һ�������ϣ��ͻ�����Ĺ�ϣ��
	USH* prev;  //�����ڴ洢λ�õ�����
	USH* head;  //��ϣ��Ŀ�ʼλ��
};





