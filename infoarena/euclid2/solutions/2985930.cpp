#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t,i,r;
    fin>>t;
    for (i=0;i<t;i++) {
        fin>>a>>b;
        while (b!=0) {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}