#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct node
{
	node* L;
	node* R;
	char self;
};

bool check(string str, int st, int fi)
{
    for (int i=st; i<=fi; i++)
        if (str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '^')
            return false;
    return true;
}

node* makeTree( string str, int st, int fi )
{
	node* root = new node;
	if (check(str, st, fi))
	{
	    if (str[st] != '(')
            root->self = str[st];
        else
            root->self = str[fi];

		root->L = root->R = NULL;
		return root;
	}

	int k = 1;
	int minP = 2147483646;
	int minPos = -1;

	for (int i = st; i <= fi; ++i)
	{
		int nowP = 2147483647;
		if (str[i] == '(') k += 3;
		if (str[i] == ')') k -= 3;
		if (str[i] == '+') nowP = k;
		if (str[i] == '-') nowP = k;
		if (str[i] == '*') nowP = k + 1;
		if (str[i] == '/') nowP = k + 1;
		if (str[i] == '^') nowP = k + 2;

		if (nowP <= minP)
		{
			minP = nowP;
			minPos = i;
		}
	}

	root->self = str[minPos];

	root->L = makeTree( str, st, minPos-1);
	root->R = makeTree( str, minPos+1, fi);

	return root;
}

void dfs( node* root)
{
	if (root->L) dfs(root->L);
	if (root->R) dfs(root->R);
	printf("%c", root->self);
}

int main(int argc, char const *argv[])
{
	int t; scanf("%d", &t);
	while (t--)
	{
		string str; cin >> str;
		node *root;
		root = makeTree(str, 0, str.length()-1);
		dfs(root);
		printf("\n");
	}
	return 0;
}
