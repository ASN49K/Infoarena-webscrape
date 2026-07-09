#include<stdio.h>
using namespace std;
int a, b, n;

FILE* in   = fopen("euclid2.in", "r");
FILE* out = fopen("euclid2.out", "w");


int cmmdc(int x, int y)
{
if(!y) return x;
return cmmdc(y, x%y); 
}  

void citire()
{
fscanf(in, "%d", &n);
for(int i=1;i<=n;i++)
{
fscanf(in, "%d %d", &a, &b);
fprintf(out, "%d\n", cmmdc(a,b));
}
}





int main()
{
citire();
return 0;
}