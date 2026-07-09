#include <fstream>

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t,i,A,B;

    fin>>t;
    for(;t>0;t--) {
        fin>>A>>B;
        fout<<gcd(A,B)<<endl;
    }
   
    fin.close();
    fout.close();

    return 0;
}
