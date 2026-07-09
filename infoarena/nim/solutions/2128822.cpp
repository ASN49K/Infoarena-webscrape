#include<fstream>
using namespace std;
int n,s,v[10000],x;
ifstream cin("nim.in");
ofstream cout("nim.out");
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        x=1;
        cin>>s;
        for(int k=1;k<=s;k++)
        {
            cin>>v[k];
            if(v[k]%2==0)
            {
                x=0;
            }
        }
        if(x==0)
        {
            cout<<"DA"<<"\n";
        }
        else
            cout<<"NU"<<"\n";
    }

}
