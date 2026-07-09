#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    return (b) ? cmmdc(b,a%b) : a;
}

int main()
{
    int n,a,b;
    f>>n;
    for(int i=0; i<n; i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
