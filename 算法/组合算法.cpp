//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main () {
//  int myints[] = {1,2,3};
//
//  cout << "The 3! possible permutations with 3 elements:\n";
//
//  sort (myints,myints+3);
//
//  do {
//    cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
//  } while ( next_permutation (myints,myints+3) );
//
//  return 0;
//}
#include<stdio.h>

char array[] = "abcd";
int queue[4];
int flag[4];
void prem(int s, int n)
{
	if (s > n)
	{
		return;
	}
	if (s == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%c ", queue[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0)
		{
			flag[i] = 1;
			queue[s] = array[i];
			prem(s + 1, n);
			flag[i] = 0;
		}
	}
}
int top = 0;
void comb(int s, int n, int m)
{
	if (s > n)
	{
		return 0;
	}
	if (top == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%c ", queue[i]);
		}
		printf("\n");
		return ;
	}
	queue[top++] = array[s];
	comb(s + 1, n, m);
	top--;
	comb(s + 1, n, m);
}
int main()
{

	//prem(0, 4);
	comb(0, 4, 3);
	return 0;
}
