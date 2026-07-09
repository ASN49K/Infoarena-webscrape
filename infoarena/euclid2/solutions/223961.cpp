#include<fstream.h>
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long t,a,b,i;
fin>>t;
for (i=1;i<=t;i++)
{fin>>a>>b;
while (a!=b)
 if (a>b) a-=b;
  else b-=a;
 fout<<a;
}
fin.close();
fout.close();
return 0;
}