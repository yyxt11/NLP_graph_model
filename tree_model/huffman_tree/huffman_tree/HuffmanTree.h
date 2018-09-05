#pragma once

/*
1):��ʼ�������ݸ�����n��Ȩֵ(��1,��2,������n)������n�ö�������ɭ�ּ���F={��1,��2,��,��n}������ÿ�ö�������iֻ��һ��ȨֵΪ��i�ĸ��ڵ㣬����������Ϊ�ա�
2):����С����������������ɭ�ּ���F��ѡȡ���ø���Ȩֵ��С������Ϊ������������һ���µĶ��������µĶ������ĸ����Ϊ�����ӵĽ�㣬��ȨֵΪ����������Ȩֵ֮�͡�
3):ɾ������룺��ɭ�ּ���F��ɾ����ѡȡ�����ø���Ȩֵ��С������ͬʱ���¹���Ķ��������뵽ɭ�ּ���F�С�
4):�ظ�2)��3)���裬ֱ��ɭ�ּ���F��ֻ��һ����Ϊֹ����������ǹ��������������Ŷ�����������2)��3)����ÿ�ظ�һ�Σ�ɾ����������������һ����������2)��3)�����ظ�n-1�μ��ɻ�ù���������
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
	void preScan();	//ǰ�������
	void midScan();	//���������
	void postScan();//���������
		
	void create(T a[], int size); //������
	void destroy(); //�ݻ���
	void print(); //��ӡ��

private:
	void forest_sort(int size);
	void preScan(hNode<T>* pnode);
	void midScan(hNode<T>* pnode);
	void postScan(hNode<T>* pnode);

	void destroy(hNode<T>* pnode);
	void print(hNode<T>* pnode);


private:
	hNode<T>* pnode; //���ڵ�
	hNode<T>* forest[MAXSIZE];
};

