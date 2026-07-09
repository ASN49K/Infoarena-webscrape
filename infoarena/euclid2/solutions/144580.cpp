#include <stdio.h>
#include <fstream>
using namespace std;

#define in "euclid2.in"
#define out "euclid2.out"

int A, B;

inline int Cmmdc(int A, int B) {
    if ( B == 0 ) return A;
    return Cmmdc(B,A%B);
}

int main()
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    
    scanf("%d%d", &A, &B);
    printf("%d\n", Cmmdc(A,B));
}
