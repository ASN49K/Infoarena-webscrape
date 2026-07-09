#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int t,n,x,i,s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        s=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            s=s^x;
        }
        if(s!=0) cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
