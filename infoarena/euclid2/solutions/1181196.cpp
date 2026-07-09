/*
    Keep It Simple!
*/

#include<fstream>
using namespace std;

int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,x,y;
    f >> T;
    while(T--)
    {
        f >> x >> y;
        g << cmmdc(x,y) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
