#include <stdio.h>
int euclid (int a,int b)
{  int aux;
if (a<b)
{aux=a;
a=b;
b=aux;
}
while(b!=0) 
{aux=a%b;
a=b;
b=aux;
}
return a;
}

int main()
{int a,b,n,i;
FILE *fin,*fout;  
fin=fopen("euclid2.in", "r");
fout=fopen("euclid2.out", "w");
fscanf(fin,"%d", &n);
for(i=n;i>0;--i)
{fscanf(fin,"%d  %d",&a , &b);
fprintf(fout,"%d\n",euclid(a, b));
}
fclose(fin);
fclose(fout);
return 0;
}
