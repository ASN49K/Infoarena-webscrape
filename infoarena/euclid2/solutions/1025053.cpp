#include <iostream>
#include <fstream>

using namespace std;
 int cmmdc(int a, int b)
  {
       if(!b) return a;
       return cmmdc(b,a%b);
  }
int main(void)
{
    int a , b, c ;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> c ;
    for(int i=1;i<=c;i++){
        f >> a; f>> b;
        g << cmmdc(a,b)<<"\n";

    }
    f.close();
    g.close();


    return 0;
}
