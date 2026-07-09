#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{int n,a,b,r,i;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>a>>b;
    if(a>=b)
    {
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        cout<<b<<"\n";
    }
    else
    {
        r=b%a;
        while(r!=0)
        {
            b=a;
            a=r;
            r=b%a;
        }
        cout<<a<<"\n";
    }

}
    return 0;
}
