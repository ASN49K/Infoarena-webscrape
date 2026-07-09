#include<fstream.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long int a,b,T;

long long int cmmdc()
{long long r;
while(b>0)
  {r=a%b;
  a=b;
  b=r;
  }
return a;
}

void eval()
{long long int i;
fin>>T;
for(i=1;i<=T;i++)
  {fin>>a>>b;
  fout<<cmmdc()<<'\n';
  }
}

int main()
{eval();
fin.close();
fout.close();
return 0;
}
