#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    int c;
    while(b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out",ios::app);
    int T,a,b;
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}
