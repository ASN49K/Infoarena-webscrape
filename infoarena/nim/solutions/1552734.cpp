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
    int n,xs=0,a;
    while(T--){
        scanf("%d ",&n);
        while(n--){
            scanf("%d ",&a);
            xs =xs ^ a;
        }
        if(xs)printf("DA\n");
        else printf("NU\n");
    }
}
