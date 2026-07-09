#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int a, int b){

int m;
if (a > b) m = b;
else m = a;

int con;

for (int i = 1; i <= m; i++){

    if (a % i == 0 && b % i == 0) con = i;

}

return con;

}

int main(){

int a, b;
int n;

fin >> n;

for (int i = 0; i < n; i++){

    fin >> a >> b;

    fout << euclid(a, b) << endl;

}

return 0;

}
