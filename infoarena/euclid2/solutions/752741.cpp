#include<stdio.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

template <class T> // template class T , T should have the operators %, =, + , / and *.Any T object should be able to become 0 following a succesion of % operations
class gcd{  // class gcd returns the simple gcd, or the solution to an ecuation
public:
  T num1, num2, res;

  gcd(){};

  gcd(pair<T, pair<T, T> > x){
    num1 = x.first;
    num2 = x.second.first;
    res = x.second.second;
  };

  T sim_euc(){
    T x = num1, y = num2, z;

    while(y){
      z = x;
      x = y;
      y = z % y;
    }

    return x;
  };

  pair<T, T> ex_euc(){
    T x = num1, y = num2, z = res, d = this.sim_euc();
    T yrx = 0, yry = 1, xrx = 1, xry = 0, aux, r1, r2;

    if(z % d != 0)
      return make_pair(0, 0);

    while(yrx * x + yry * y){
      r1 = xrx * x + xry * y;
      r2 = yry * y + yrx * x;
      aux = yrx;
      yrx = xrx - (r1 / r2) * yrx;
      xrx = aux;
      aux = yry;
      yry = xry - (r1 / r2) * yry;
      xry = aux;
    }

    return make_pair(xrx * z / d, xry * z / d);
  };

};

gcd<int> x;

int main(){
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  int t;
  scanf("%d", &t);

  while(t){
    --t;
    int aux1, aux2;
    scanf("%d%d", &aux1, &aux2);

    x.num1 = aux1;
    x.num2 = aux2;

    printf("%d\n", x.sim_euc());
  }

  return 0;
}
