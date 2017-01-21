#include "NQueue.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

NQueue::NQueue(int length):_length(length),_sum(0)
{
	_x = new int[length];
}

bool NQueue::Place(int k)
{
	for(int i = 0; i < k; ++i)
	{
		if( (abs(k-i) == abs(_x[k]-_x[i]) ) || _x[k] == _x[i] )
			return false;
	}
	return true;
}

void NQueue::BackTrack(int k)
{
	if( k >= _length )
	{
		++_sum;
		for(int i = 0; i < _length; ++i)
		{
			std::cout << _x[i] << " ";
		}
		std::cout << std::endl;
		return;
	}
	else
	{
		for(int i = 0; i < _length; ++i)
		{
			_x[k] = i+1;
			if( Place(k) )
			{
				BackTrack(k+1);
			}
		}	
	}
	
}

void NQueue::NBackTrack()
{
	int k = 0,j = 0;
	_sum = 0;
	while( k >= 0 && k < _length )
	{
		while( j < _length )
		{
			_x[k] = j+1;
			if( !Place(k) )
			{
				++j;
			}
			else
				break;
		}
		if( j < _length )
		{
			if( k == _length - 1 )
			{
				++_sum;
				for(int k = 0; k < _length; ++k)
				{
					std::cout << _x[k] << " ";
				}
				std::cout << std::endl;
				++j;
			}
			else
			{
				++k;
				j = 0;
			}

		}
		else
		{
			j = _x[k-1]+1;
			--k;
		}
	}
}

NQueue::~NQueue()
{
	if( _x != NULL )
		delete _x;
}
