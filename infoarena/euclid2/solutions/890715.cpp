#include <stdio.h>
using namespace std;

int CMMDC(int a,int b){
    if(b==0)
        return a;
    return CMMDC(b,a%b);
}

int main()
{
    int i,n,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d\n",&a,&b);
        printf("%d\n",CMMDC(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
