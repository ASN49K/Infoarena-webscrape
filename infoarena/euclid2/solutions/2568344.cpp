#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a,b,r;
    int n;
    fin>>n;
    while(n>0){
            fin>>a;
            fin>>b;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    n--;
    fout<<a<<endl;
    }

    return 0;
}
