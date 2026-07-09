#include <iostream>
#include <fstream>
#include <stdio.h>
//using namespace std;
//
//int euclid(int a, int b)
//{
//    if(a==b)
//        return a;
//    else
//        if(a>b)
//            return euclid(a-b,b);
//        else
//            return euclid(a,b-a);
//}
//
//int euclid2(int a, int b)
//{
//    if(b==0)
//        return a;
//    else
//        return euclid2(b,a%b);
//}
//
//int main()
//{
//    ifstream f("euclid2.in");
//    ofstream g("euclid2.out");
//    long t,a,b;
//    f>>t;
//    for(long i=1;i<=t;i++)
//    {
//        f>>a>>b;
//        g<<euclid2(a,b)<<endl;
//    }
//}
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
