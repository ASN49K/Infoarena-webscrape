#include<fstream.h>
int main()
{ifstream fin("euclid.in");
ofstream fout("euclid.out");
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