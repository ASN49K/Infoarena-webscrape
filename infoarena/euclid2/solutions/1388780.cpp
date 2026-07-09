#include <fstream>
#include <iostream>
using namespace std;

int ggt(int a, int b)
{
    if(!b)
        return a;
    else
        return ggt(b, a%b);
}
int a,b,i;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>i;
    for(int k=1;k<=i;k++)
    {
        fin>>a;
        fin>>b;
        fout<<ggt(a,b)<<" \n";
    }
    return 0;
}
