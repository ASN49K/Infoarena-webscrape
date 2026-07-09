#include<fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int sum,n,x,y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>y;
            sum^=y;
        }
        if(sum)
            cout<<"DA"<<'\n';
        else
            cout<<"NU"<<'\n';
    }
}
