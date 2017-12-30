/*
用类对象实现单链表 顺序栈 和环形队列
*/

#include"singe_linked_list.h"
#include"stack.h"
#include"circular_queue.h"
#include<iostream>
using namespace std;

int main()
{
	/*
	******************************************************
	单链表
	******************************************************
	*/
	List mylist;
	//插入 0~9
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	//打印最后一个节点_data 并且pop出最后一个节点
	while (!mylist.empty())
	{
		cout << mylist.back() << " ";
		mylist.pop_back();
	}
	cout << endl;

	/*
	******************************************************
	顺序栈
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
	环形队列
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
