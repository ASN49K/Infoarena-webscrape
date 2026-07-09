#include <iostream>
#include <fstream>
using namespace std;
int gcd (int* a,int* b)
{
    int* r;
    *r=*a%*b;
    if (*r==0)
    {
        return *b;
    }
    else
    {
        gcd (b,r);
    }
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int x,y,nr;
    f>>nr;
    while (nr-->0){

            f>>x>>y;
    g<<gcd(&x,&y);
    }
    return 0;
}
