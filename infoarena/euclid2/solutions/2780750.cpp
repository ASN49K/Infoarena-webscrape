#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void euclid(int &a, int b){

while (a != b){

    if (a > b) a = a - b;
    else b = b - a;

}

}

int main(){

int a, b, n;

fin >> n;

while (fin >> a >> b){

    euclid(a, b);

    fout << a << std::endl;

}

return 0;

}
