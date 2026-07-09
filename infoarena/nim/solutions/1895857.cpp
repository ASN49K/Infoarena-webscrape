#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");

long long n,i,j,x,sum,t;

int main()
{
     cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>n; cin>>sum;
        for(j=2;j<=n;++j)
        {
            cin>>x;
            sum = (sum^x);
        }

        if(sum>0) {cout<<"DA\n";}
        else cout<<"NU\n";
    }
    return 0;
}
