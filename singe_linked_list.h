/*
带头节点的单链表
*/

#pragma once
#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include<iostream>
using namespace std;


struct Node
{
	Node(int data = 0, Node *next = NULL)
		:_data(data)
		,_next(next){}

	int _data;
	Node *_next;
};

class List
{
public:
	List()
	{
		_head = new Node;
	}

	~List()
	{
		Node *tmp;
		while (_head)
		{
			tmp = _head->_next;
			delete _head;
			_head = tmp;
		}
	}

	//尾插
	void push_back(int val)
	{
		//先从头结点开始遍历，找到_next为NULL的节点
		Node *cur = _head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}

		//此时cur的_next为NULL,插入新的节点
		cur->_next = new Node(val);
	}

	//在链表的第pos个位置之前插入元素
	bool insert(int pos, int val)
	{
		Node *cur = _head;
		while (--pos && cur->_next != NULL)
		{
			cur = cur->_next;
		}

		cur->_next = new Node(val);
	}

	//pop出最后的一个节点
	void pop_back()
	{
		if (empty())
		{
			return;
		}

		Node *cur = _head;
		Node *pre;
		while (cur->_next != NULL)
		{
			pre = cur;
			cur = cur->_next;
		}

		pre->_next = cur->_next;
		delete cur;
	}

	//返回最后一个节点的_data
	int back()
	{
		Node *cur = _head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		return cur->_data;
	}

	bool empty()
	{
		return _head->_next == NULL;
	}
private:
	Node *_head;
};


#endif // !SINGLE_LINKED_LIST
