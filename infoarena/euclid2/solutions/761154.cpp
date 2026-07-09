#include <cstdio>
#include <algorithm>
using namespace std;

int cmmdc(int a,int b){
    if(b==0)return a; else return cmmdc(b,a%b);
}

int main(){
    int t,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
