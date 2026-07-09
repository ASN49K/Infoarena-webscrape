#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    int n,t,x,s;
    scanf("%d",&n);
    while(n--){
        s=0;
        scanf("%d",&t);
        while(t--){
            scanf("%d",&x);
            s^=x;
        }
        if(s) printf("DA\n");
        else printf("NU\n");
    }

    return 0;
}
