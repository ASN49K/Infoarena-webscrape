#include<fstream.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b;

int cmmdc1(int a,int b) {
    if(!b)
        return a;
    return cmmdc1(b,a%b);
}

void citire () {
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
