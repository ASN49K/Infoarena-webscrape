#include<fstream.h>
int i,j,r;
int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>i>>j;
while(j!=0)
{r=i%j;
i=j;
j=r;}
g<<i;
f.close();
g.close();
return 0;
}