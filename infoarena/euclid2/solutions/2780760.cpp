#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int a, int b){

if (b==0) return a;
return euclid(b, a % b);

}

int main(){

long long a, b;
int n;

fin >> n;

for (int i = 0; i < n; i++){

    while (fin >> a >> b){

    a = euclid(a, b);

    fout << a << std::endl;

}

}

return 0;

}
