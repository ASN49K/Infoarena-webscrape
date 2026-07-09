#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,i,z;
    fin >> t;
    for (i=0;i<t;++i){
        fin >> a >> b;
        while(b!=0)
        {
            z=a%b;
            a=b;
            b=z;
        };
        fout << a << "\n";
    }

    return 0;
}
