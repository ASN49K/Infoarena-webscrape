#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   int t;
   f >> t;
   for (int i = 1; i <= t; i++){
        int a, b;
        f >> a >> b;
        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        g << a << endl;
   }
}

