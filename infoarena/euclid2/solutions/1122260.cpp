#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a, b, r;
int main()
{in>>a>>b;
while(b!=0){r=b;b=a%b;a=r;}
   out<<a ;
 return 0;
}
