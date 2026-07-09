#include<fstream.h>
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r;
fin>>a;
fin>>b;
while(b>0)
{r=a%b;
a=b;
b=r;
}
fout<<a;
fin.close();
fout.close();
return 0;
}