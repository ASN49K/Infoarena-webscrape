#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(a * b == 0)
        return a + b;
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


void citire()
{
    int T, a, b;

    fin >> T;

    while(T > 0)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << endl;
            T --;
    }

}

int main()
{
    citire();

    return 0;
}
