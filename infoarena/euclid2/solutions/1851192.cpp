#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,c,x;
    f >> a;
    f >> b;
    for(int i = 1; i<=x; i++){
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g << a;
    }
    return 0;
}
