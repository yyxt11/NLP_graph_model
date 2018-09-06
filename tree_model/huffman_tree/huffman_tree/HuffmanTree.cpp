#include "HuffmanTree.h"

template<typename T>
void HuffmanTree<T>::forest_sort(int start,int size)
{
	//ð�ݷ�����,�ƿ�仯
	for (int i = start; i< start + size - 1; i++)
	{
		for (int j = i+1; j < start + size; j++)
		{
			if ��forest[i]->weight > forest[j]->weight��
			{
				swap(forest[i],forest[j]);
			}

		}

	}

}


template<typename T>
void HuffmanTree<T>::preScan()
{

}

template<typename T>
void HuffmanTree<T>::midScan()
{
}

template<typename T>
void HuffmanTree<T>::postScan()
{
}

template<typename T>
void HuffmanTree<T>::create(T a[], int size)
{	
	//nodeɭ�ֳ�ʼ��
	for (int i = 0; i < size; i++)
	{
		hNode<T> *ph = new hNode<T>(a[i], NULL, NULL);
		forest[i] = ph;
	}

	int window_s = 0;
	int round = 0;

	//ѡȡ����Ȩ����С������node
	for (int j = 0; j < size-1; j++)
	{	
		
		//������
		forest_sort(window_s, size - round);

		//�ҵ���С��Ȩ�ص�
		hNode<T> *node = new hNode<T>(forest[window_s]->weight + forest[window_s + 1]->weight, 
									  forest[window_s], 
									  forest[window_s + 1]);
		forest[size+round] = node;

		start += 2;
		round++;

	}

	pnode = forest[size + round - 1]

}

template<typename T>
void HuffmanTree<T>::destroy()
{
}

template<typename T>
void HuffmanTree<T>::print()
{
}

template<typename T>
void HuffmanTree<T>::preScan(hNode<T>* pnode)
{
}

template<typename T>
void HuffmanTree<T>::midScan(hNode<T>* pnode)
{
}

template<typename T>
void HuffmanTree<T>::postScan(hNode<T>* pnode)
{
}

template<typename T>
void HuffmanTree<T>::destroy(hNode<T>* pnode)
{
}

template<typename T>
void HuffmanTree<T>::print(hNode<T>* pnode)
{
}
