#include <cstdio>
#include <map>
#define key 666013
#define FOR1(l,n,j) for(register int i=l;i<=n;i+=j){scanf("%d%d",&a,&b);printf("%d\n",euclid(a,b));}
#define FOR2() for(it=h.begin();it!=h.end();it++){val=it->second;printf("%d ",val);}

using namespace std;

map<int,int>h;
map<int,int> ::iterator it;
int euclid(int a, int b){
    int c;
    if(b==0)return a;
    c=euclid(b,a%b);
    return c;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    FOR1(1,n,1)

    return 0;
}
