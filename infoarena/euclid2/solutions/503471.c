#include <stdio.h>
#include <stdlib.h>
int x,y,d;
int tc;
int compGCD(int A, int B) {

        while (A % B != 0) {
            int C = A % B;
            A = B;
            B = C;
        }
        return B;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);


    scanf("%d",&tc);

    while(tc) {
        int gcdnow;
        scanf("%d %d",&x,&y);
        gcdnow = compGCD(x,y);
        printf("%d\n",gcdnow);
        tc--;
    }

    return 0;
}
