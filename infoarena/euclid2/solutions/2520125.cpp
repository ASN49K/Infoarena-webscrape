#include    <iostream>
using namespace std;

int main()
{
   int n,v[202];
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>v[i];
    for(int i=1;i<=n+1;i++){
      if(v[i]%2==0 && v[i+1]%2==0)
        v[i+1]=(v[i]+v[i+1])/2;
          n++;
    }
    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
}
