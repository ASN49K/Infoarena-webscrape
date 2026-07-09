#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int x,a,b;
    in>>x;
    while(x>0)
    {
        in>>a>>b;
        a=euclid(a,b);
        out<<a<<'\n';
        x=x-1;
    }
}
