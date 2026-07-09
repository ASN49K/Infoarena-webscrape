#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,x[200001];
int cmmdc(int &a, int &b) {
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
    fin>>n;
    for(i=1;i<=2*n;i++)
        fin>>x[i];
    for(i=1;i<=2*n-1;i++) {
        fout<<cmmdc(x[i], x[i+1])<<endl;
        i++;
    }
    return 0;
}
