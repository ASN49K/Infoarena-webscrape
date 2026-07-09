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

int i, N, v[214748364], a, b;

int main()
{
    f>>N;

    for(i = 1; i<= N; i++)
    {
        f>>a>>b;
        g<<sht(a, b)<<endl;
    }


    f.close();
    g.close();
}
