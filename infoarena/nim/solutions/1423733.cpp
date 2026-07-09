#include<fstream>
using namespace std;
int n, i, sum, t, x;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main(){
    fin>> t;
    for(; t; t--){
        sum = 0;
        fin>> n;
        for(i = 1; i <= n; i++){
            fin>> x;
            sum = (sum ^ x);
        }
        if(sum == 0){
            fout<<"NU\n";
        }
        else{
            fout<<"DA\n";
        }
    }
    return 0;
}
