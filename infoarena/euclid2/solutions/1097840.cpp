#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{if(b==0)return a;
 else return cmmdc(b,a%b);
}
int t,i,x,y;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {f>>x>>y;
     g<<cmmdc(x,y)<<endl;
    }
    return 0;
}
