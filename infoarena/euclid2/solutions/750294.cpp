#include <cstdio>
#define TEST 0

void open_file(){
    if(TEST)
    {
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    } else
    {
        freopen("euclid2.in","r",stdin);
        freopen("euclid2.out","w",stdout);
    }
}

int n,a,b;

int cmmdc(int a,int b){
    if(b == 0) return a; else return cmmdc(b,a%b);
}

int main(){
    open_file();

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
