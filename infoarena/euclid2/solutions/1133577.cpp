#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int a, int b)
{
    if(b==0)
        return a;
    else
        return CMMDC(b, a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t,a, b;
    fin>>t;
    while(t!=0)
    {
        fin>>a>>b;
        fout<<CMMDC(a,b)<<endl;
        t--;
    }
    return 0;
}
