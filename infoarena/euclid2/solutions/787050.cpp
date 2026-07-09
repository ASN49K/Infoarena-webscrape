#include<cstdio>
#include<assert.h>

using namespace std;

class euclid{
private:

  int cmmdc(int x, int y){
    int z;

    while(y){
      z = x;
      x = y;
      y = z % y;
    }

    return x;
  }

public:

  void solve(){
    assert(freopen("euclid2.in", "r", stdin));
    assert(freopen("euclid2.out", "w", stdout));

    int cases;

    scanf("%d", &cases);

    for(int i = 0; i < cases; ++i){
      int num1, num2;
      scanf("%d%d", &num1, &num2);
      printf("%d\n", cmmdc(num1, num2));
    }

  }

} t;

int main(){
  t.solve();

  return 0;
}
