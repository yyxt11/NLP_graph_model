#include "HuffmanTree.h"

template<typename T>
void HuffmanTree<T>::forest_sort(int start,int size)
{
	//冒泡法排序,移框变化
	for (int i = start; i< start + size - 1; i++)
	{
		for (int j = i+1; j < start + size; j++)
		{
			if （forest[i]->weight > forest[j]->weight）
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
	//node森林初始化
	for (int i = 0; i < size; i++)
	{
		hNode<T> *ph = new hNode<T>(a[i], NULL, NULL);
		forest[i] = ph;
	}

	int window_s = 0;
	int round = 0;

	//选取其中权重最小的两个node
	for (int j = 0; j < size-1; j++)
	{	
		
		//重排序
		forest_sort(window_s, size - round);

		//找到最小的权重点
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
