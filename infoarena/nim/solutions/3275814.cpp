#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int n,t,x,y,s;

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        s=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            s=s^x;
        }
        if(s!=0)
            cout << "DA"<<'\n';
        else cout<<"NU"<< '\n';
    }
    return 0;
}
