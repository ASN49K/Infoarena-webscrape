#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int a, int b){

while (a != b){

    if (a > b) a -= b;
    else b -= a;

}

return a;

}

int main(){

int a, b;
int n;

fin >> n;

while (n){

    fin >> a >> b;

    fout << euclid(a, b) << endl;

    n--;

}

return 0;

}
