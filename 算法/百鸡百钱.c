#include<stdio.h>
int main()
{

  for(int i=0;i<=100;i++)
  {
  for(int j=0;j<=100;j++)
  {
      int z=100-i-j;
      if(z%3==0)
     {
         if(5*i+3*j+z/3==100)
     {
      printf("%d %d %d\n",i,j,z);
     }
     }

  }
  }


 return 0;
}
