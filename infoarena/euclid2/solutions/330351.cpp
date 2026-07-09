#include <iostream>
#include <fstream>

using namespace std;


long eu (long a, long b)
{
    if (b==0)
    {
        return a;
    }
    else eu (b,a%b);
}

int main()
{
    long a,b,n;
    ofstream fout ("euclid2.out");
    ifstream fin ("euclid2.in");
        fin >> n;
        for (int i=1; i<=n; i++)
        {
            fin >> a >> b;
            fout << eu(a,b) <<endl;
        }
    fin.close();
    fout.close();
    return 0;
}
