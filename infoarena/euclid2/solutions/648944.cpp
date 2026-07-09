#include <stdio.h>
int main()
  {
          int x[50],n,i,s,a=0;
          printf("Introduceti dimensiunea sirului. \n");
          scanf("%d",&n);
       printf("Introduceti elementele sirului. \n");
for (i=1;i<=n;i++)
		scanf("%d", &x[i]);
	for (i=1;i<=n;i++)
	{
	  if (s==x[i])
	  a++;}
	  if (a>=n/2)
{ printf("Exista.\n");
 printf("\n");}
 else
  printf("Nu exista.\n");
  printf("\n");
 return 0;
}
