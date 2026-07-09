/*
@romocoder
*/
#include <cstdio>
#include <algorithm>

using namespace std;
void go();
int main()
{
 freopen("euclid2.in", "r", stdin);
 freopen("euclid2.out", "w", stdout);
 
 int T;
 scanf("%d\n", &T); 
 while (T--) go();
 return 0;    
}
/*
int __gcd(int a, int b) 
{
 if (!b) return a;
 return __gcd(b, a%b);
}
*/

void go() 
{
 int a, b;
 scanf("%d %d", &a, &b);
 printf("%d\n", __gcd(a, b));
}
//RomoCoder in action AGAIN!
