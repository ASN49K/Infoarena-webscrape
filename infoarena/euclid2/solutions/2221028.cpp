#include <fstream>
#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    int c;
    while(a != b && b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t;
    fin>>t;
    while(t>0)
    {
        t--;
        fin>>a>>b;
        fout<<cmmdc(a,b);
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
