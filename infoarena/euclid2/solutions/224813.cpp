#include<fstream.h>
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int i,a,b,r,n;
fin>>n;
for (i=1;i<=n;i++)
{
fin>>a;
fin>>b;
while(b>0)
{r=a%b;
a=b;
b=r;
}
fout<<a;
}
fin.close();
fout.close();
return 0;
}