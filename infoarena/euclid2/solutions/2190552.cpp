#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in.txt");
ofstream g("euclid2.out.txt");


int main()
{
    int a,b;
    f>>a>>b;

    for(int i=a;i>=1;i--)
        if(a%i==0 && b%i==0)
        {
        g<<i;
        i=0;
         }



    return 0;
}
