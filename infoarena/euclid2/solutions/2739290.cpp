#include <bits/stdc++.h>
using namespace std;
int main()
{
    int teste,n,m,r[100],p=0;
    cin>>teste;
    while(teste!=0)
    {
        cin>>n>>m;
        while(n!=m)
            if(n>m)
                n-=m;
            else
                m-=n;
        r[p++]=n;
        teste--;
    }
    for(int i=0;i<p;++i)
        cout<<r[i]<<endl;
    return 0;
}
