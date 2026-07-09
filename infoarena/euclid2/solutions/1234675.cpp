#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,rest;
int main()
{
    fin>>n;
    while (n) {
    fin>>a>>b;
    do
    {
        rest=a%b;
        a=b;
        b=rest;
    }while (rest!=0);
    fout<<a<<endl;n--;}
    return 0;
}
