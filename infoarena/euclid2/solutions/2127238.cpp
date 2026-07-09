#include <iostream>
#include<fstream>
using namespace std;
int T,a,b,i,v[100];
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>T;
    int k=0;
    for(i=1; i<=T; i++)
    {
        int r;
        cin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        v[++k]=a;
    }
    for(i=1; i<=k; i++)
        cout<<v[i]<<endl;
}
