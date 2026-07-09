#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int t,n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        int sum=0;
        for (int j=1;j<=t;j++)
        {
            int a;
            cin>>a;
            sum=sum^a;
        }
        if (sum)
            cout<<"DA"<<'\n';
        else
            cout<<"NU"<<'\n';
    }
}
