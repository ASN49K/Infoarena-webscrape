#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{int a,b,r,x;
fin>>x;
while(x>0)
{fin>>a>>b;
while(a%b!=0)
{r=a%b;
a=b; b=r;
}
fout<<b<<"\n";
x--;
}
fin.close();
fout.close();
return 0;
}