#include<fstream>

using namespace std;

int euclid(int a, int b){
  if (a == 0 || b == 0)
    return a + b;
  else if (a > b)
    return euclid(a%b,b);
  else
    return euclid(a,b%a);
}

int main(){  
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int x, y, n;
f >> n;
for(int i = 1; i <= n; i++){
  f >> x >> y;
  g << euclid(x,y) << '\n';
}

f.close();
g.close();
}
