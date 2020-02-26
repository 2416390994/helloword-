
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

// hashAddr����һ�ι�ϣ��ַ ch�����л�������һ���ַ� 
// pos��ch�ڻ��������е�λ�� matchHead�����ƥ�䣬����ƥ�䴮����ʼλ��
void LZHashTable::Insert(USH& hashAddr, UCH ch, USH pos, USH& macthHead)
{
	// �����ϣ��ַ 
	HashFunc(hashAddr, ch);
	// ����ѹ���Ĳ��Ͻ��У�pos�϶������WSIZE������WMASK��֤��Խ�� 
	prev[pos & HASH_MASK] = head[hashAddr];
	macthHead = head[hashAddr];
	head[hashAddr] = pos;
}

//���������ϣ��ַ�ĺ���
//���εĹ�ϣ��ַ������һ�ι�ϣ��ַ�Ļ����ϼ��������
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
		//�ȸ���head
		if (head[i] >= WSIZE)
			head[i] -= WSIZE;
		else
			head[i] = 0;
	

		//����prev
		if (prev[i] >= WSIZE)
			prev[i] -= WSIZE;
		else
			prev[i] = 0;
	}

	
}