#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int t,n;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int s=0,x;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            s=s^x;
        }
        if(s==0)
            cout<<"NU"<<'\n';
        else
            cout<<"DA"<<'\n';
    }
    return 0;
}
