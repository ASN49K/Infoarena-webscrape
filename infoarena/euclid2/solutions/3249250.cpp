#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, x, y;
    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>x>>y;
        while(x!=y) {
            if(x>y)
                x=x-y;
            else
                y=y-x;
        }
        fout<<x<<endl;
    }

    return 0;
}
