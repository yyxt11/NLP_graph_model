#include "HuffmanTree.h"


template<typename T>
void HuffmanTree<T>::forest_sort(int start,int size)
{
	//冒泡法排序,移框变化
	for (int i = start; i< start + size - 1; i++)
	{
		for (int j = i+1; j < start + size; j++)
		{
			if (forest[i]->weight > forest[j]->weight)
			{
				swap(forest[i],forest[j]);
			}

		}

	}

}


template<typename T>
void HuffmanTree<T>::preScan()
{
	preScan(this->pnode);
}

template<typename T>
void HuffmanTree<T>::midScan()
{
	midScan(this->pnode);
}

template<typename T>
void HuffmanTree<T>::postScan()
{
	postScan(this->pnode);
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

	int startp = 0;
	int round = 0;

	//选取其中权重最小的两个node
	for (int j = 0; j < size-1; j++)
	{	
		
		//重排序
		forest_sort(startp, size - round);

		//找到最小的权重点
		hNode<T> *node = new hNode<T>(forest[startp]->weight + forest[startp + 1]->weight,
									  forest[startp],
									  forest[startp + 1]);
		forest[size + round] = node;

		startp += 2;
		round++;

	}

	pnode = forest[size + round - 1];

}

template<typename T>
void HuffmanTree<T>::destroy()
{
	if (pnode != NULL)
	{
		destroy(this->pnode);
	}
}


template<typename T>
void HuffmanTree<T>::print()
{
	print(this->pnode);
}

template<typename T>
void HuffmanTree<T>::preScan(hNode<T>* pnode)
{
	if (pnode != NULL)
	{
		cout << "前序遍历当前节点：" << pnode->weight << ".";
		preScan(pnode->lchild);
		preScan(pnode->rchild);
	}

}

template<typename T>
void HuffmanTree<T>::midScan(hNode<T>* pnode)
{
	if (pnode != NULL)
	{	
		midScan(pnode->lchild);
		cout << "中序遍历当前节点：" << pnode->weight << ".";
		midScan(pnode->rchild);
	}

}

template<typename T>
void HuffmanTree<T>::postScan(hNode<T>* pnode)
{
	if (pnode != NULL)
	{
		postScan(pnode->lchild);
		postScan(pnode->rchild);
		cout << "后序遍历当前节点：" << pnode->weight << ".";
	}

}

template<typename T>
void HuffmanTree<T>::destroy(hNode<T>* pnode)
{
	if (pnode != NULL)
	{
		this->destroy(pnode->lchild);
		this->destroy(pnode->rchild);
		delete pnode;
	}
}

template<typename T>
void HuffmanTree<T>::print(hNode<T>* pnode)
{
	if (pnode != NULL)
	{
		cout << "当前节点权重：" << pnode->weight << ".";

		if (pnode->lchild != NULL)
		{
			cout << "当前节点左孩子权重：" << pnode->lchild->weight << ".";
		}
		else 
		{
			cout << "当前结点无左孩子节点：" ;
		
		}

		if (pnode->rchild != NULL)
		{
			cout << "当前节点右孩子权重：" << pnode->rchild->weight << ".";
		}
		else
		{
			cout << "当前结点无右孩子节点：" ;

		}
		cout << endl;
		print(pnode->lchild);
		print(pnode->rchild);

		
	}
}



int main()
{
	HuffmanTree<int> HT;
	int a[] = { 10,20,30,40 };
	HT.create(a, 4);
	HT.print();

	system("pause");
}