#include<fstream>
using namespace std;
int main()
{int n,a,b,i,r;
ifstream f1("euclid2.in");
ofstream f2("euclid2.out");
f1>>n;
for(i=1;i<=n;i++)
{f1>>a>>b;
while(b)
{r=a%b;
a=b;
b=r;
}
f2<<a<<'\n';
}





return 0;
}
