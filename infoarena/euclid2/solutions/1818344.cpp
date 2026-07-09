#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, x, y, r;
    fin >> n;

    for(int i=1;i<=n;i++)
    {
        fin >> x >> y;
        while(y)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout << x << endl;
    }
    return 0;
}
