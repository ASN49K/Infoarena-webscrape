#include<fstream>
#include<iostream>
using namespace std;
int a,b,x;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>a>>b;
    while(b)
    {
        x=a%b;
        a=b;
        b=x;

    }
    fout<<a;
}
