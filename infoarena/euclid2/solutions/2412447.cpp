#include <fstream>
#include <stdio.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long n;
unsigned long long a,b;

unsigned long long cmmdc(unsigned long long a, unsigned long long b){
if(!b) return a;
else return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    while(n)
    {
        scanf("%d %d", &a, &b);
        if(a>b) swap(a,b);
        printf("%d\n", cmmdc(a,b));
        n--;
    }

    return 0;
}
