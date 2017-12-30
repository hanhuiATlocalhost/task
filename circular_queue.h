#pragma once
#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

class circular_queue
{
public:
	circular_queue(int size = 10)
		:_size(size)
		, _head(0)
		, _tail(0)
	{
		_base = new int[_size + 1];
	}

	~circular_queue()
	{
		delete[] _base;
	}

	int size()
	{
		return (_tail + _size - _head) % _size;
	}

	bool empty()
	{
		return _head == _tail;
	}

	bool full()
	{
		return (_tail + 1) % _size == _head;
	}

	void push(int val)
	{
		if (full())
		{
			resize();
		}

		_base[_tail] = val;
		_tail = (_tail + 1 + _size) % _size;
	}

	void pop()
	{
		if (empty())
		{
			return;
		}

		_tail = (_tail - 1 + _size) % _size;
	}

	int back()
	{
		return _base[(_tail - 1 + _size) % _size];
	}

private:
	void resize()
	{
		int *tmp = new int[_size * 2];
		int i = 0;
		while (_head != _tail)
		{
			_head = (_head + _size + 1) % _size;
			tmp[i] = _base[_head];
			i++;
		}
		delete[] _base;
		_base = tmp;
		_size *= 2;
		_head = 0;
		_tail = i;
	}

	int _size;
	int _head;//队头下标
	int _tail;//队尾下标,这个队尾下标是无效的数据
	int *_base;
};

#endif // !CIRCULAR_QUEUE
