#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc (int a, int b){
int c;
while (b>0)
{
    c=b;
    b=a%b;
    a=c;
}
return a;
}

int main()
{
    int t,x,y,i;
    f>>t;
    for (i=1; i<=t; i++){
            f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
