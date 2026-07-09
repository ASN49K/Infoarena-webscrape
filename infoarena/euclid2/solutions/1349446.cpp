#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long int n, a, b;
    in>>n;
    while(in>>a>>b)
    {
        while(a!=b)
        if(a>b)
        a=a-b;
    else b=b-a;
        out<<a<<endl;
        }
    return 0;
}
