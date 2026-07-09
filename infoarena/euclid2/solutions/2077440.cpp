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

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.outs");
    int a,b,n;
    fin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        fin >> a >> b;
        fout << euclid(a,b) << endl;
    }
    return 0;
}
