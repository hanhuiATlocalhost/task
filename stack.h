/*
顺序栈：
*/

#pragma once
#ifndef STACK
#define STACK

#include<memory>

class stack
{
public:
	stack(int maxsize = 10)
		:_maxsize(maxsize)
		,_size(0)
	{
		_base = new int[_maxsize];
	}

	~stack()
	{
		delete[] _base;
	}

	bool full()
	{
		return _maxsize == _size;
	}

	bool empty()
	{
		return _size == 0;
	}

	void push(int val)
	{
		if (full())
		{
			resize();
		}

		_base[_size] = val;
		_size++;
	}

	void pop()
	{
		if (empty())
		{
			return;
		}

		_size--;
	}

	int top()
	{
		return _base[_size - 1];
	}
	
private:
	void resize()
	{
		int *tmp = new int[_maxsize * 2];
		memcpy(tmp, _base, _size * sizeof(int));//一开始忘记加sizeof(int)
		delete[] _base;
		_base = tmp;
		_maxsize *= 2;
	}

	int *_base;
	int _maxsize;
	int _size;
};

#endif // STACK
