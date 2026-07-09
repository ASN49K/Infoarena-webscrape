#include <fstream>

using namespace std;

int T;

int CMMDC(int A, int B);

int main()
{

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);

    for(int i=1;i<=T;++i)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", CMMDC(A, B));
    }
    return 0;
}

int CMMDC(int A, int B)
{
    if(!B)  return A;
    return CMMDC(B, A % B);
}
