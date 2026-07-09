#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out ("euclid2.out");
    int x,a,b,rest;
    in>>x;
    for(int i=1; i<=x; i++)
    {
        in>>a>>b;
        while(b!=0) //while(b)
    {
        rest =a%b;
        a=b;
        b=rest;

    }
     out<<a<<"\n";
    }
    return 0;
}
