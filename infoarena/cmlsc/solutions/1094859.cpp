#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    if(b == 0) return -1;
    while(a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}
int main()
{
    int n, a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(int i = 0; i < n ; i++)
    {
        fin>>a;
        fin>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();

    return 0;
}
