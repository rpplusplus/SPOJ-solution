#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	int five[12];
	int tmp = 1;
	for (int i=0; i<12; i++)
	{
		tmp *= 5;
		five[i] = tmp;
	}
	
	int t; scanf("%d", &t);
	while (t--)
	{
		int x; scanf("%d", &x);
		int result = 0;
		for (int i=0; i<12; i++)
			result += x / five[i];
		printf("%d\n", result);
	}
	return 0;
}

