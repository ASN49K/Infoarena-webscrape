#include <iostream>
#include <fstream>

using namespace std;

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int T;
int euclid(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    fin >> T;
    for(int i = 0; i < T; ++i)
    {
        int a,b;
        fin >> a;
        fin >> b;
        fout << euclid(a,b)<<"\n";
    }
    fout.close();
    fin.close();
    return 0;
}
