#include <cstdio>
using namespace std;
int euclid(int a,int b)
{
 if (a%b)return euclid(b,a%b);
    else return b;
}
int t,a,b;
int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%d",&t);
 for(;t;--t){
             scanf("%d%d",&a,&b);
             printf("%d\n",euclid(a,b));
             }
 return 0;
}
 
