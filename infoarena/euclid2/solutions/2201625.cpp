#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,T;
    f >> T;

    for(int i=1;i<=T;i++){
        f >> a >> b;
        int minim = a < b ? a : b;
        int cmmdc;

        for(int i=1;i<=minim;i++)
            if(a%i==0 && b%i==0) cmmdc = i;
        g << cmmdc << endl;
    }
}
