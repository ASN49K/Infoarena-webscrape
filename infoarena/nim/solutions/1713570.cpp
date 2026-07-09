#include<fstream>
using namespace std;
int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    int t,n,ans=0,x;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        ans=0;
        cin>>n;
        for(int j=1;j<=n;++j)
        {
            cin>>x;
            ans=ans^x;
        }
    if(ans)
        cout<<"DA"<<endl;
    else
        cout<<"NU"<<endl;
    }
    return 0;
}
