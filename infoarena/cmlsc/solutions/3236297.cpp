#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int v[1025], cnt, x, y, a;

int main()
{
    cin>>x>>y;
    for(int i=1;i<=x;i++)
    {
        cin>>a;
        v[a]++;
    }
    for(int i=1;i<=y;i++)
    {
        cin>>a;
        v[a]++;
        if(v[a]==2)
            cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=1024;i++)
        if(v[i]>1)
            cout<<i<<" ";
}
