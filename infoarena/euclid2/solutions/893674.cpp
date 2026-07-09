#include <iostream>
#include <fstream>
using namespace std;
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");
int nr, a, b,i;
 int heuclid (int x, int y)
{
    fin>>nr;
    while (fin>>a>>b)
    {
        if(y==0)
        return x;
        else
        return heuclid(y,x%y);
    }
}
 int main()
{
    gout<<heuclid (a, b)<<endl;
return 0;
 }
