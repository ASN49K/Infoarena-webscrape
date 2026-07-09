#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int recursiv(int a,int b)
{
    if(!b)
        return a;
    return recursiv(b,a%b);
}
int main()
{
    int a,b;
    fin>>a>>b;
    fout<<recursiv(a,b);
    return 0;
}
