#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    int n,k,v[1024],a[1024],cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<k;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(v[i]==a[i])
                cnt++;
        }
    }
    cout<<cnt<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(v[i]==a[i])
                cout<<v[i]<<" ";
        }
    }
}
