#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		int a;
		scanf("%d%d", &n, &a);
		if (n >= 3 || n <= 0)
		{
			printf("-1 -1\n");
		}
		else
		{
			if (n == 1)
			{
				printf("1 %d\n", a + 1);
			}
			else
			{
				if (n == 2)
				{
					int b, c;
					if (a % 3 == 0)
					{
						b = (a / 3) * 4;
						c = (a / 3) * 5;
						printf("%d %d\n", b, c);
					}
					else
					{
						if (a % 4 == 0)
						{
							b = (a / 4) * 3;
							c = (a / 4) * 5;
							printf("%d %d\n", b, c);
						}
						else
						{
							printf("-1 -1\n");
						}
					}
				}
			}
		}
	}
	return 0;

}
