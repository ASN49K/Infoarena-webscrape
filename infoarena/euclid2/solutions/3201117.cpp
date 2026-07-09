#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,x,y,div;
    fin>>n;
    for(int i=1;i<=n ; i++)
    {
        fin>>x>>y;
        while(y)
        {
            div=x%y;
            x=y;
            y=div;
        }
        fout<< x<< endl;
    }
    return 0;
}