#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int a, int b){

 if(b == 0)
        return a;

    return euclid(b, a % b);
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
