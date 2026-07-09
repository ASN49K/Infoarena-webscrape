#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("file.in");
ofstream fout("file.out");

int n, a, b;

int main(){

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> a >> b;
        while(a != b){
            if(a > b)a = a - b;
            else b = b - a;
            //cout << a << "\n";
        }
        fout << a << "\n";
    }

    return 0;
}