#include <cstdio>

void euclid(int a,int b,int &d){
    if(b == 0)
    {
        d = a;
        return ;
    }
        euclid(b,a%b,d);
}

int main(){
    int t,a,b,d;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d",&a,&b);
            euclid(a,b,d);
            printf("%d\n",d);
        }

    return 0;
}
