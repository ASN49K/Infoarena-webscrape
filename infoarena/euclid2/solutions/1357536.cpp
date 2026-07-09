#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n , x , y , r;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        r = x%y;
        while(y != 0)
        {
            r = x%y;
            x = y;
            y = r;
        }
        fout<<x<<endl;
    }
    return 0;
}
