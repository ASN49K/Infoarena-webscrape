#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void gcd(int a, int b)
{
    unsigned c;
    if(b>a)
    {
        swap(a, b);
    }
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout <<a << endl;
}


int main()
{
    int a, b, T;
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        fin >> a >> b;
        gcd(a, b);
    }


    return 0;
}
