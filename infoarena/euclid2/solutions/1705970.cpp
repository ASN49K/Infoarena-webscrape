#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int CMMDC(int a, int b)
{int r;
    while(b!=0)
    {r=a%b;
     a=b;
     b=r;
    }
    return a;
}
int n;
int main()
{int i,x,y;
    cin>>n;
    for (i=1;i<=n;i++)
    {cin>>x>>y;
     cout<<CMMDC(x,y)<<"\n";
    }
    cin.close();
    cout.close();
    return 0;
}
