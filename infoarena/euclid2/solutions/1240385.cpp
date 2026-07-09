#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
int a,b,r,n;
for(int i =1;i<=n;i++)
{
    scanf( "%d%d", &a, &b );
  while ( b > 0 ) {
    r = a % b;
    a = b;
    b = r;
  }
    printf( "%d", a );
}


  return 0;
}
