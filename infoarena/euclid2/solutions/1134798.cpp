#include <cstdio>

int eu(int a,int b){
    if(b)return eu(b,a%b);
    return a;
}

int main()
{
    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);
    int a,b,n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",eu(a,b));
    }

}
