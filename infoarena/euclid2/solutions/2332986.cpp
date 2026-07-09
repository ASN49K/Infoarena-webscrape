#include <cstdio>
using namespace std;

int A,B,T;

int euclid(int a,int b)
{
    if(b==0)return a;
    return euclid(b,a%b);
}

int main() {

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&T);

    for(int i=1;i<=T;i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }

    return 0;
}