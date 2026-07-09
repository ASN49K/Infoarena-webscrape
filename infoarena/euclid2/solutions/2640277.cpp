#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int x;
    fin >> x;
    for(int i=1; i<=x; i++)
    {
        int n, m;
        fin >> n >> m;
        while(n!=m)
        {
            if(n>m)
                n-=m;
            else
                m-=n;
        }
        fout << m << endl;
    }
    return 0;
}
