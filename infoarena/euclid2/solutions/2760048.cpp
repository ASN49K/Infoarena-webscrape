#include <iostream>
#include <fstream>

using namespace std;

int lnko(int a, int b)
{
    if(b==0) return a;
    else lnko(b, a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int x,y;
    f>>x;
    while(f>>x){
        f>>y;
        if(x>y) g<<lnko(x,y)<<endl;
        else g<<lnko(y,x)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
