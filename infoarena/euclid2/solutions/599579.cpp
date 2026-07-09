#include <stdio.h>
#include <fstream>
#include<iostream>

int rest;
int euclid(int a, int b)
{
int c;
while (b!=0) {
rest = a % b;
a = b;
b = rest;
}
return a;
//printf("%d",a);

}

int main()

{int a,b,rest;int n;
FILE *f,*g;
f= fopen("euclid2.in","r");
g= fopen("euclid2.out","w");

fscanf(f,"%d\n",&n);

		for(int i=0;i<n;i++){
	fscanf(f,"%d %d\n",&a,&b);
	fprintf(g,"%d\n",euclid(a,b));
}




return 0;
}

