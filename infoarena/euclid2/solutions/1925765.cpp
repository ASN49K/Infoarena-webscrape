#include <cstdio>
using namespace std;

inline int cmmdc(int a,int b){

    int r=a%b;
    while (r){
        a=b;
        b=r;
        r=a%b;
        }
    return b;
}

void Solve(){

    int a,b,n;
    scanf("%d",&n);

    while (n--){
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
        }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    Solve();
    return 0;
}
