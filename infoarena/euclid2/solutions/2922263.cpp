#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int s,a[500],b[500],nr,ok;
void afisare(int len)
{
    ok=1;
    for(int i=1;i<=len;++i)printf("%d ",a[b[i]]);
    printf("\n");
}
void backt(int k,long long p)
{
    for(int i=b[k-1]+1;i<=nr&&p*a[i]<=s;++i)
    {
        b[k]=i;
        p*=a[i];
        if(p>s);
        else if(p==s)afisare(k);
        else backt(k+1,p);
        p/=a[i];
    }
}
int main()
{
    scanf("%d",&s);
    //backt(0,1,0);
    for(int i=2;i*i<=s;++i)
    {
        if(s%i==0)
        {
            a[++nr]=i;
            if(i*i<s)a[++nr]=s/i;
        }
    }
    sort(a+1,a+nr+1);
    backt(1,1);
    if(ok==0)printf("NU EXISTA");
    return 0;
}
