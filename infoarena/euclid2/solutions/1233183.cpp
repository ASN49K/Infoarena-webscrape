#include<cstdio>
using namespace std;
int t, a, b, c;
void swap(int &a, int &b){int aux=a; a=b; b=aux;}
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &t);
    while (t>0) {
        scanf("%d%d", &a, &b);
        if (b>a) swap(a, b);
        while (a%b!=0) {c=a%b; a=b; b=c;}
        printf("%d\n", b); t--;
    }
    return 0;
}
