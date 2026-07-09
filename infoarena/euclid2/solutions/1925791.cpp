#include <cstdio>
using namespace std;
int n,a,b,z;
inline int cmmdc(int a, int b){

    while (b != 0) {
        z = a;
        a = b;
        b = z % b;
    }
    return a;
};

int main()
{
    freopen("euclid2.in", "rb", stdin);
    freopen("euclid2.out", "wb", stdout);
    scanf("%d",&n);
    for(int index = 0; index < n; index++){
        scanf("%d %d", &a,&b);
        printf("%d\n", cmmdc(a,b));
    }
    fclose(stdin);

    return 0;
}
