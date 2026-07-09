#include <iostream.h>
#include <stdio.h>
using namespace std;

int i,j,n,k;
int ciur[10000];


int main()
{   freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
   cin>>n;

    for(i=2;i<=(n/2);i++)
      for(j=2;(j*i)<=n;j++)
        ciur[j*i]=1;
        
    for(i=2;i<n;i++)
      if(ciur[i]==0)
        cout<<i<<" "<<endl;;    
        
    return 0;
}        
