#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
    ofstream out("euclid2.out");

int main()
{

    int a,b,c;
    in>>a>>b;
    while (b)
        {
            c=a%b;
    a=b;
    b=a;
        }
        out<<a;
    return 0;
}
