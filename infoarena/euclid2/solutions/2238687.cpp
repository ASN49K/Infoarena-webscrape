#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int a,b;
    fin>>a>>b;
    while (a!=b)
        {
        if(a>b)
        a=a-b;
        else
        b=b-a;
        }
    fout<<a;
    return 0;
}
