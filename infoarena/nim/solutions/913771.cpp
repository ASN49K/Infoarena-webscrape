#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out","w", stdout);
    int t;
    scanf("%d", &t);
    while(t --){
        int n;
        scanf("%d", &n);
        int s = 0;
        while(n --){
            int x;
            scanf("%d", &x);
            s = s ^ x;
        }
        if(s != 0){
            printf("DA\n");
        }else{
            printf("NU\n");
        }
    }

    return 0;
}
