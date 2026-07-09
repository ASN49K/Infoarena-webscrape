
#include <iostream>

#include <fstream>

using namespace std;
int euclid(int a, int b){
if (!b) return a;
return euclid(b,a%b);
}

int main()
{ int n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for (int i=0; i<n; i++){
    int a,b;
    fin>>a>>b;
    fout<<euclid(a,b)<<endl;
}
    return 0;
}
