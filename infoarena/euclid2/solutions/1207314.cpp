/*#include <iostream>
#include <fstream>
using namespace std;
int n,a,b;

int gcd(int a, int b){
if(!b)return a;
return gcd(b,a%b);
}

int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(;n;n--){
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    f.close();
    g.close();
}*/
#include <stdio.h>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}
