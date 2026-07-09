#include <fstream>
using namespace std;
int main()
{   int a, b, n, r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1; i<=n; i++)
    {   f>>a>>b;
        if(a<b){r=a; a=b; b=r;}
        while(b){
        r=a%b;
        a=b;
        b=r;}
    g<<a<<'\n';}
    return 0;
    }

