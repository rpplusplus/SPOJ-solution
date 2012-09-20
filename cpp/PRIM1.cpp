#include <stdio.h>
#include <math.h>
#include <string.h>

#define maxn 31624
#define maxm 3510

int prime_arr[maxm];
int cnt;
bool temp_arr[maxn];

void calc_prime_arr()
{
	memset(temp_arr, false, sizeof(temp_arr));
	int tmp = (int) sqrt(maxn);
	for (int i = 2; i <= tmp; ++i)
	{
		if (!temp_arr[i])
		{
			int t = i * 2;
			while (t < maxn)
			{
				temp_arr[t] = true;
				t += i;
			}
		}
	}

	cnt = 0;
	for (int i = 2; i < maxn; ++i)
	{
		if (!temp_arr[i])
		{
			prime_arr[cnt] = i;
			cnt++;
		}
	}
}

void prime(long x, long y)
{
	for (long i = x; i <= y; ++i)
	{
		if (i == 1) continue;
		bool flag = true;
		for (int j = 0; j < cnt; ++j)
		{
			if (sqrt(i) < prime_arr[j]) break;

			if (i % prime_arr[j] == 0 && i != prime_arr[j])
			{
				flag = false;
				break;
			}
				
		}
		if (flag)
		{
			printf("%ld\n", i);
		}
	}
}
int main()
{
	// freopen("test.txt", "r", stdin);
	// freopen("test1.txt", "w", stdout);
	calc_prime_arr();
	int n; scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		if (i != 0) printf("\n");

		long x, y;
		scanf("%ld %ld", &x, &y);
		prime(x, y);
	}
	return 0;
}

// 999899999 999999999 

