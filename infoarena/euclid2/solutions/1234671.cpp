#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int main()
{
    fin>>n;
    while (n) {
    fin>>a>>b;
    while (a!=b)
    {
        if (a>b) a-=b;
        else b-=a;
    }
    fout<<a<<endl;n--;}
    return 0;
}
