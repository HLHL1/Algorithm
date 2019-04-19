
//方法一：递归实现
#include<stdio.h>
#include<stdlib.h>

void Merge(int*a, int low,int mid, int high)
{
	int*b = (int *)malloc((high - low + 1)*sizeof(int));
	int i = low, j = mid + 1,k=0;
	while (i <= mid&&j <= high)
	{
		if (a[i] > a[j])
		{
			b[k] = a[j];
			k++;
			j++;
		}
		else
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}
	while (i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	k = 0;
	for (int i = low; i<=high; i++)
	{
		a[i] = b[k];
		k++;
	}
	free(b);
}
void Merge_sort(int* a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		Merge_sort(a, low, mid);
		Merge_sort(a, mid + 1, high);
		Merge(a, low,mid, high);
	}
}
int main()
{
	int a[] = { 9, 8, 7,  5, 4, 3, 2, 1 };
	int sz = sizeof(a) / sizeof(a[0]);
	Merge_sort(a,0,sz-1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//方法二：非递归实现
//归并排序
#include<stdio.h>
#include<stdlib.h>

void Merge(int*a, int low,int mid, int high)
{
	int*b = (int *)malloc((high - low + 1)*sizeof(int));
	int i = low, j = mid+1, k = 0;
	while (i <= mid&&j <= high)
	{
		if (a[i] > a[j])
		{
			b[k] = a[j];
			k++;
			j++;
		}
		else
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}
	while (i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	k = 0;
	for (int i = low; i <= high; i++)
	{
		a[i] = b[k];
		k++;
	}
	free(b);
}
void Merge_pass(int*a, int length, int sz)
{
	int i ;
	for (i = 0; i + 2*length-1 < sz; i = i + 2 * length)
	{
		Merge(a, i,i+length-1, i + 2*length-1);

	}
	if (i + length - 1 < sz - 1)
	{
		Merge(a, i,i+length-1, sz - 1);
	}
}
int main()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int length = 1; length < sz; length = length*2)
	{
		Merge_pass(a, length, sz);
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
