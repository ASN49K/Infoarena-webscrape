#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[257],b[257];
int main()
{
    int n,m,i,nr,s=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
      cin>>nr;
      a[nr]++;
    }
    for(i=1;i<=m;i++)
    {
      cin>>nr;
      b[nr]++;
    }
    for(i=0;i<=256;i++)
    {
      if(a[i]<b[i])
        s+=a[i];
      else{
       s+=b[i];
       a[i]=b[i];
      }
    }
    cout<<s<<endl;
    for(i=0;i<=256;i++)
    {
      while(a[i])
      {
        cout<<i<<" ";
        a[i]--;
      }
    }
    return 0;
}
