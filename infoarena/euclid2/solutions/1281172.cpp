#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(int a=1;a<=n;a++)
    {
        unsigned long long x,y,c;
        fin>>x>>y;
        while(y)
        {
            c=x%y;
            x=y;
            y=c;
        }
        fout<<x<<endl;
    }
}
