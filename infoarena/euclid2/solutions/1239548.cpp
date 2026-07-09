#include<cstdio>
using namespace std;

int gcd(int x, int y){
  int z;
  while(y){
    z = x;
    x = y;
    y = z % y;
  }
  return x;
}

int main() {

    int t = 0, a = 0, b = 0;

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);

    for (int i = 1; i <= t; ++i) {
        scanf("%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }

    return 0;
}
