
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long cmmdc(long long a,long long b)
{long long r;
while(b)
{r=a%b;
a=b;
b=r;
}
return a;

}
long long a,b,t,i;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
        {f>>a>>b;g<<cmmdc(a,b)<<'\n';}


    return 0;
}
