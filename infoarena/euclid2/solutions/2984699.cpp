#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int name(int num1, int num2){
    while(num1 != num2){
        if(num2 > num1){
            int aux = num1;
            num1 = num2;
            num2 = aux;
        }
        num1 = num1 % num2;
    }
    return num1;
}


int main(){
    int nums;
    fin >> nums;
    int num1, num2;
    for(int i = 1; i <= nums; ++i){
        fin >> num1 >> num2;
        fout << name(num1, num2);
    }
}
