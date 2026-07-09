// http://www.infoarena.ro/problema/euclid2

#include <fstream>

using namespace std;

int euclid(int a, int b) {
    int r = a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n;
    f>>n;

    int a, b;
    for(int i=0;i<n;++i){
        f>>a>>b;
        g<<euclid(a, b)<<"\n";
    }

    return 0;
}
