#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t;
    f>>t;
    while(t--){
        int s=0,n;
        f>>n;
        while(n--){
            int x;
            f>>x;
            s^=x;
        }
        if(s) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
