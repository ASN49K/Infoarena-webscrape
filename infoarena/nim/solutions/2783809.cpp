#include <fstream>

using namespace std;
ifstream Gigi ("nim.in");
ofstream Marcel ("nim.out");

int main()
{
    int t,n,m;
    int xors;
    Gigi>>t;
    while(t--){
        Gigi>>n;
        xors=0;
        while(n--){
            Gigi>>m;
            xors^=m;
        }
        if (xors) Marcel<<"DA\n";
        else Marcel<<"NU\n";
    }
    return 0;
}
