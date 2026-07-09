#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

long GCD (long a, long b)
{
    long r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    long T, A, B;
    fin >> T;
    for (; T>0; --T)
    {
        fin >> A >> B;
        fout << GCD (A, B) << "\n";
    }
    fin.close ();
    fout.close ();
    return 0;
}
