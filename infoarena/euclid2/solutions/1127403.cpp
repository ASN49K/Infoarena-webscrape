#include<fstream>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,r,n,i;
f>>n;
for(i=1;i<=n;i++)
{f>>a>>b;
while(b!=0)
  {r=a%b;
  a=b;
  b=r;	
  }
g<<a<<endl;	
}
f.close();
g.close();
return 0;	
}
