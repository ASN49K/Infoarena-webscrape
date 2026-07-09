#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int a, int b)
{
    if(b == 0)
        return a;
    else
        return CMMDC(b,a%b);
}

int main()
{

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T,a,b;
    in >> T;
    while(in >> a >> b)
    {
        out<<CMMDC(a,b)<<endl;
    }

    return 0;
}
