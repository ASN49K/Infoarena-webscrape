#include <iostream>
#include<limits.h>
using namespace std;

int main()
{
    int i,j,a[100],lung[100],poz[100],n,index;
    cin>>n;
    for(i=1;i<=n;i++)
    {cout<<"a["<<i<<"]=";
    cin>>a[i];
}
    for(i=n;i>=1;i--)

        {lung[i]=1;poz[i]=-1;
         for(j=n;j>i;j--)
        if(a[i]<a[j]&&1+lung[j]>lung[i])
    {
        lung[i]=lung[j]+1;
        poz[i]=j;
    } }
int maxim=INT_MIN;
for(i=1;i<=n;i++)
        if(lung[i]>maxim)
{maxim=lung[i];
index=i;

} cout<<maxim<<endl;
while(index!=-1)
{
    cout<<a[index]<" ";
    index=poz[index];
}
return 0;
