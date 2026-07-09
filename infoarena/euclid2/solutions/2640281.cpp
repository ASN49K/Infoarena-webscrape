#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //ifstream fin("date.in");
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin >> t;

    while(t--){
        int a, b, ans = 1;
        fin >> a >> b;

        if(a % 2 == 0){
            while(a % 2 == 0)
                a = a / 2;

            ans = 2;
        }
        if(b % 2 == 0){
            while(b % 2 == 0)
                b = b / 2;

            ans = 2;
        }
        int i;
        for(i = min(a,b); i >= 3; i -= 2){
            //cout << i << " ";
            if(a % i == 0 && b % i == 0){
                fout << ans * i << "\n";
                break;
            }
        }
        if(i == 1)
            fout << 1 << "\n";
    }


    return 0;
}
