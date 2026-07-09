#include <stdio.h>

int main(){
    int a,b,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        while(b) {
        	int r = a % b;
        	a = b;
			b = r;        	
		}
        printf("%d\n", a);
    }
    return 0;
}
