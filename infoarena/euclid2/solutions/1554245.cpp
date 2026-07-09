#include <cstdio>

using namespace std;



int euclid(int a, int b){
        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t,x,y,r;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d", &x, &y);
        int z=euclid(x,y);
        printf("%d\n", z);
    }
    return 0;
}
