#include "HuffmanTree.h"

template<typename T>
void HuffmanTree<T>::forest_sort(int size)
{
	//ð�ݷ�����
	for (int i = 0; i<size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
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

	//ѡȡ����Ȩ����С������node
	for ()


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
