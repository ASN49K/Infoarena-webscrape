#include<fstream.h>

using namespace std;

ofstream fout("euclid2.out");

int T;
long a,b;

int cmmdc1(long a,long b) {
    if(!b)
        return a;
    return cmmdc1(b,a%b);
}

void citire () {
    ifstream fin ("euclid2.in");
    fin>>T;
    for(int i=0;i<T;i++) {
        fin>>a>>b;
        fout<<cmmdc1(a,b)<<endl;
    }
    fin.close();
}


int main()
{
    citire();
    fout.close();
   return 0;
}
