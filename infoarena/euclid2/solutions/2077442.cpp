#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int m;
    while(b)
    {
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{

    long long a,b,n;
    fin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        fin >> a >> b;
        fout << euclid(a,b) << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
