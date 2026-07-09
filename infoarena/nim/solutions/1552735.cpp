#include <cstdio>

using namespace std;

int T;

void Read();

int main(){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    Read();
    return 0;
}
void Read(){
    scanf("%d ",&T);
    int n,xs,a;
    while(T--){
        scanf("%d ",&n);
        xs=0;
        while(n--){
            scanf("%d ",&a);
            xs =xs ^ a;
        }
        if(xs)printf("DA\n");
        else printf("NU\n");
    }
}
