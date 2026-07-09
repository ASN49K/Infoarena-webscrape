#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,x;
std::vector<int> a,b,c;
bool cmp(int A,int B)
{
    return A>B;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&x);
        b.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);

    while(a.size()!=0&&b.size()!=0)
    {
        if(a[a.size()-1]==b[b.size()-1])
        {
            c.push_back(a[a.size()-1]);
            a.pop_back();
            b.pop_back();
        }
        else if(a[a.size()-1]>b[b.size()-1])
        {
            b.pop_back();
        }
        else a.pop_back();
    }
    printf("%d\n",c.size());
    for(int i=0;i<c.size();++i)printf("%d ",c[i]);
    return 0;
}
