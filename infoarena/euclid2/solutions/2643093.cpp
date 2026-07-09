#include <iostream>
#include <fstream>
using namespace std;

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    int cmmdc (int a,int b) {
        if (a%b==0) return b;
        if (a<b) cmmdc (b,a);
        return cmmdc (b,a%b);
    }
int main()
{
    int t;
    fin>>t;
    while (t) {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc (a,b)<<endl;
        --t;
    }
    return 0;
}
