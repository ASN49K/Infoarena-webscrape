#include <iostream>
#include <fstream>
using namespace std;
int a,b,r;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>a>>b;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a;
    fin.close();
    fout.close();
    return 0;
}
