
#include <iostream>

#include <fstream>

using namespace std;
long long euclid(long long a, long long b){
if (a==b) return a;
if (a>b) return euclid(a-b,a); else return euclid(a, b-a);
}

int main()
{ long n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for (long i=0; i<n; i++){
    long long a,b;
    fin>>a>>b;
    fout<<euclid(a,b)<<endl;
}
    return 0;
}
