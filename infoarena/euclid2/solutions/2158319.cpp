#include <fstream>

using namespace std;

int a, b, T;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int CMMDC(int a, int b)
{
    if(b == 0)
        return a;
    else
        return CMMDC(b, a%b)
}

int main()
{
    for(int i = 1; i<=T ; i++)
    {
        fin >> a >> b;
       fout << CMMDC(a,b) <<"\n";
    }

}
