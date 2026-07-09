#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int name(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main(){
    int nums;
    fin >> nums;
    int num1, num2;
    for(int i = 1; i <= nums; ++i){
        fin >> num1 >> num2;
        fout << name(num1, num2) << '\n';
    }
}
