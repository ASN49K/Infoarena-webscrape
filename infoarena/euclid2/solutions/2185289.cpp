#include <fstream>
using namespace std;
int n, a, b, i;

int cmmdc (int a, int b)
{
    int r=0;
    if (a==0)
        return b;
    else {
        if (b==0)
            return a;
        else {
            while (b!=0) {
                r=a%b;
                a=b;
                b=r;
            }
        }
    }

    return a;
}

int main () {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }

    return 0;
}
