#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void cmmdc(int a, int b)
{
    if (b==0) {g << a << '\n' ; return ;}
    return cmmdc (b, a%b);
}

int main()
{
    int T,x,y;
 f >> T;
 while(T--)
 {
     f >> x >> y;
     cmmdc(x,y);
 }
}
