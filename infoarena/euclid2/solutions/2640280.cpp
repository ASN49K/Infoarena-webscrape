#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin >> t;

    while(t--){
        int a, b;
        fin >> a >> b;

        for(int i = min(a,b); i >= 1; --i){
            if(a % i == 0 && b % i == 0){
                fout << i << "\n";
                break;
            }
        }
    }


    return 0;
}
