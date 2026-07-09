#include "stdio.h"
	int main()
		{
			int nr=0,i;
			printf("Numerele sunt: ");
			for(i=1000;i<=9999;i++)
				{
					if(i%67==23)
						{
						nr++;						
						printf("%d ",i);
						}
				}
			printf("\n");
			printf("Sunt %d numere",nr);
			return 1;
		}
