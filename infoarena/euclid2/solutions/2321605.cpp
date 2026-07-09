#include <iostream>
#include <fstream>
using namespace std;
int r;
int cmmdc(int a, int b)
{
    if(a < b)
    {

    a += b;
    b = a - b;
    a -= b;
    }
    r = a%b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main(){
int n,x,y;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f >> n;
for(int i = 0; i < n;i++)
{
    f >> x >> y;
   g << cmmdc(x, y) << "\n";
}

}
