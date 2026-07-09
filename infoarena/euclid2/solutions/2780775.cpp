#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

long long euclid(long long a, long long b){

 while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){

long long a, b;
int n;

fin >> n;

for (int i = 0; i < n; i++){

    fin >> a >> b;

    fout << euclid(a, b) << endl;

}

return 0;

}
