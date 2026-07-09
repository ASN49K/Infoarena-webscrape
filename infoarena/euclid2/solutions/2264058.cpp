#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,n,i;
    f>>n;
    for(i=0;i<n;i++){
    f>>a>>b;
    while(a != b)
{
    if(a>b)
        a=a-b;
    if(b>a)
        b=b-a;}
    g<<a<<"\n";
    }
f.close();
g.close();
    return 0;
}
