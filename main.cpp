/*
�������ʵ�ֵ����� ˳��ջ �ͻ��ζ���
*/

#include"vld.h"
#include"singe_linked_list.h"
#include"stack.h"
#include"circular_queue.h"
#include<iostream>
using namespace std;

int main()
{
	/*
	******************************************************
	������
	******************************************************
	*/
	List mylist;
	//���� 0~9
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	//��ӡ���һ���ڵ�_data ����pop�����һ���ڵ�
	while (!mylist.empty())
	{
		cout << mylist.back() << " ";
		mylist.pop_back();
	}
	cout << endl;

	/*
	******************************************************
	˳��ջ
	******************************************************
	*/
	stack s;
	for (int i = 0; i < 20; i++)
	{
		s.push(i);
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	/*
	******************************************************
	���ζ���
	******************************************************
	*/
	circular_queue que;
	for (int i = 0; i < 20; i++)
	{
		que.push(i);
	}

	while (!que.empty())
	{
		cout << que.back() << " ";
		que.pop();
	}
	cout << endl;

	return 0;
}