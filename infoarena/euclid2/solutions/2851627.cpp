#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int sht(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int i, N, v[214748364];

int main()
{
    f>>N;

    for(i = 1; i<= 2 * N; i = i+2)
    {
        f>>v[i]>>v[i+1];
        g<<sht(v[i], v[i+1])<<endl;
    }


    f.close();
    g.close();
}
