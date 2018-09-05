#pragma once

/*
1):初始化：根据给定的n个权值(Ｗ1,Ｗ2,…，Ｗn)，构造n棵二叉树的森林集合F={Ｔ1,Ｔ2,…,Ｔn}，其中每棵二叉树Ｔi只有一个权值为Ｗi的根节点，左右子树均为空。
2):找最小树并构造新树：在森林集合F中选取两棵根的权值最小的树做为左右子树构造一棵新的二叉树，新的二叉树的根结点为新增加的结点，其权值为左右子树的权值之和。
3):删除与插入：在森林集合F中删除已选取的两棵根的权值最小的树，同时将新构造的二叉树加入到森林集合F中。
4):重复2)和3)步骤，直至森林集合F中只含一棵树为止，这颗树便是哈夫曼树，即最优二叉树。由于2)和3)步骤每重复一次，删除掉两棵树，增加一棵树，所以2)和3)步骤重复n-1次即可获得哈夫曼树。
from https://blog.csdn.net/tanswer_/article/details/52794335
*/
#define MAXSIZE 100000
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
struct hNode {
	hNode(T w, hNode<T>* l, hNode<T>* r) :T(w), lchild(l), rchild(r), flag(0) {}

	T weight;
	hNode<T>* lchild;
	hNode<T>* rchild;
	int flag;

};

template <typename T>
class HuffmanTree
{
public:
	void preScan();	//前序遍历树
	void midScan();	//中序遍历树
	void postScan();//后序遍历树
		
	void create(T a[], int size); //创建树
	void destroy(); //摧毁树
	void print(); //打印树

private:
	void forest_sort(int size);
	void preScan(hNode<T>* pnode);
	void midScan(hNode<T>* pnode);
	void postScan(hNode<T>* pnode);

	void destroy(hNode<T>* pnode);
	void print(hNode<T>* pnode);


private:
	hNode<T>* pnode; //根节点
	hNode<T>* forest[MAXSIZE];
};

