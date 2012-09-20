#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define maxn 10000

using namespace std;

class bigNumber
{
public:
	bigNumber()
	{
		_length = 1;
		_array = new vector<int>(5);
		for (int i = 0; i < 5; ++i) (*_array)[i] = 0;
		printf("%s\n", "空构造函数");
	}

	bigNumber(int n)
	{
		_length = 1;
		_array = new vector<int>(5);
		for (int i = 0; i < 5; ++i) (*_array)[i] = 0;
		(*this) = n;
		printf("%s\n", "int 构造函数");
	}
	~bigNumber()
	{
		delete _array;
		printf("%s\n", "析构函数");
	}

	bigNumber operator * (bigNumber x)
	{
		bigNumber result;
		result.setLength( x.getLength( ) + this->getLength() );

		for (int i = 0; i < this->getArray().size(); ++i)
		{
			for (int j = 0; j < x.getArray().size(); ++j)
			{
				result.getArray()[i + j - 1] += this->getArray()[i] * x.getArray()[j];
				if (result.getArray()[i + j - 1] >= maxn)
				{
					result.getArray()[i + j] += result.getArray()[i + j - 1] / maxn;
					result.getArray()[i + j - 1] %= maxn;
				}
			}
		}

		while (result.getArray()[result.getLength()-1] == 0 || result.getLength() != 1)
			result.setLength( result.getLength() - 1);
		printf("%s\n", "高乘高");
		return result;
	}	

	bigNumber operator * (int x)
	{
		bigNumber _x( x );
		printf("%s\n", "高乘低");
		return (*this) * _x;
	}

	bigNumber operator = (int x)
	{
		_length = 0;
		while (x > 0)
		{
			(*_array)[_length++] = x % maxn;
			x /= maxn;
		}
		printf("%s\n", "整数赋值");
		return *this;
	}

	void setLength(int _len)
	{
		_length = _len;
	}

	int getLength()
	{
		return _length;
	}

	vector<int> getArray()
	{
		return *_array;
	}

	void print()
	{
		printf("%d", (*_array)[0]);
		for (int i = 1; i < _length; ++i)
			printf("%.4d", (*_array)[i]);
		printf("\n");
	}
private:
	int _length;
	vector<int> *_array;
};

int main(int argc, char const *argv[])
{
	bigNumber a = 1;

	for (int i = 2; i < 100; ++i)
	{
			a = a * i;
	}	

	a.print();
	return 0;
}