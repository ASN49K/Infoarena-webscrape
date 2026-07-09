#include <iostream>
#include <fstream>

using namespace std;

int lnko(int a, int b)
{
    if(!b) return a;
    else lnko(b, a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,x,y;
    f>>n;
    for(; n>0; n--){
        f>>x>>y;
        g<<lnko(x,y)<<endl;
    }
    return 0;
}
