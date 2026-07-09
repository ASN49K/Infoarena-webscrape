#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int T,a,b,r=0;

ifstream n("euclid2.in");
ofstream D("euclid2.out");
n >> T;
do{
n >> a >> b;
r=a%b;
    while(r)
    {
    a=b;
    b=r;
    r=a%b;
    }
    if (b != 1) D << b<< endl;
    else D << 1 << endl;

    T--;
}while(T>0);
}
