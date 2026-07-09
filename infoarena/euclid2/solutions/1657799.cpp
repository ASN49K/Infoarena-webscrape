
#include <iostream>

#include <fstream>

using namespace std;
long long euclid(long long a, long long b){
if (!b) return a;
return euclid(b,a%b);
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
