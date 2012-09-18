#include <cstdio>
#include <cstdlib>

int reverse(int x)
{
	int result = 0;
	while (x > 0)
	{
		result *= 10;
		result += (x % 10);
		x /= 10;
	}

	return result;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", reverse( reverse(a) + reverse(b) ) );
	}
}