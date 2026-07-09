#include <iostream>
#include <fstream>
using namespace std;

int main()
{
int n , v[1001];
cin>>n;
int i , j;
int copie=n;
for(i=1;i<=n;i++)
{
    cin>>v[i];
}
int con=0;
for(i=1;i<=n;i++)
{
    int copie=v[i];
    cout<<copie<<" ";
    for(j=i+1;j<=n;j++)
    {
        v[i]=copie;
        cout<<v[i]<< " "<<v[j]<<" " ;
        int r=v[i]%v[j];

        while(r!=0)
        {
             v[i]=v[j];
             v[j]=r;
             r=v[i]%v[j];
        }
        int cmmdc=v[j];

        if(cmmdc==1)
            con++;
    }d
}
return 0;
}
