#include <fstream>

using namespace std;

int gcd(int a,int b)
{
    int r;
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t,i,a,b;

    fin>>t;
    for(i=1;i<=t;i++) {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
   
    fin.close();
    fout.close();

    return 0;
}
