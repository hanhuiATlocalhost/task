/*
��ͷ�ڵ�ĵ�����
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

	//β��
	void push_back(int val)
	{
		//�ȴ�ͷ��㿪ʼ�������ҵ�_nextΪNULL�Ľڵ�
		Node *cur = _head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}

		//��ʱcur��_nextΪNULL,�����µĽڵ�
		cur->_next = new Node(val);
	}

	//������ĵ�pos��λ��֮ǰ����Ԫ��
	bool insert(int pos, int val)
	{
		Node *cur = _head;
		while (--pos && cur->_next != NULL)
		{
			cur = cur->_next;
		}

		cur->_next = new Node(val);
	}

	//pop������һ���ڵ�
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

	//�������һ���ڵ��_data
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
