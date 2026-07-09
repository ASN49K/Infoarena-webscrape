#include <iostream>
 
using namespace std;
 
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
 
    int t,n,i,j,x;
 
    scanf("%d",&t);
    for(i=0;i<t;i++) {
        scanf("%d",&n);
        int s=0;
        for(j=0;j<n;j++) {
            scanf("%d",&x);
            s^=x;
        }
        if(s>0) printf("DA\n");
        else printf("NU\n");
    }
 
    return 0;
}
