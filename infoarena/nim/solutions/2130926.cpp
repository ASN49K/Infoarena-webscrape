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
        x=0;
        cin>>s;
        for(int k=1;k<=s;k++)
        {
            cin>>v[k];
            x=x^v[k];
        }
        if(x!=0)
        {
            cout<<"DA"<<"\n";
        }
        else
            cout<<"NU"<<"\n";
    }

}
