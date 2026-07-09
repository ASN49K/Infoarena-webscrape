#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main(){

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        while(a != b){
            if(a > b)
                if(a % b != 0)
                    a = a % b;
                else 
                    a = a - b;
            else 
                if(b % a != 0)
                    b = b % a;
                else 
                    b = b - a;
            //cout << a << "\n";
        }
        fout << a << "\n";
    }

    return 0;
}