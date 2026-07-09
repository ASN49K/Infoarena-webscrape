#include <fstream>

using namespace std;
ifstream cin ("nim.in");
ofstream cout ("nim.out");

int main()
{
    int t,nr,n,i,j,s;
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n;
        s=0;
        for (j=1;j<=n;j++)
        {
            cin>>nr;
            s=s^nr;
        }
        if (s)
            cout<<"DA";
        else
            cout<<"NU";
        cout<<'\n';
    }
    return 0;
}
