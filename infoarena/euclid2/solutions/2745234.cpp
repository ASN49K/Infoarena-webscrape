#include<fstream>
#include<algorithm>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b){
    if(b)
      return cmmdc(b, a % b);
}

/**
      while(b){
        int r = a % b;
        a = b;
        b = r;
      }

*/

int main()
{
   int n;
   cin >> n;
   for(int i = 1; i <= n; ++i){
       int a, b;
       cin >> a >> b;
       cout << cmmdc(a, b) << '\n';
   }

   return 0;
}
