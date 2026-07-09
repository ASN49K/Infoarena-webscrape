#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,c;
    f >> a;
    f >> b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    printf("DA!");
    return 0;
}
