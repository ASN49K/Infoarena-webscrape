#include <fstream>
#include <iostream>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int leastCommonDiv(unsigned int a,unsigned int b){
    if (a == 0)return b;
    if (b == 0)return a;

    if (a % 2 == 0){
        if (b % 2 == 0)
            return 2 * leastCommonDiv(a / 2, b / 2);
        else{
            return leastCommonDiv(a / 2, b);
        }
    }
    else{
        if(b % 2 == 0)
            return leastCommonDiv(a, b / 2);
        else{
            if(a > b)
                return leastCommonDiv((a - b) / 2, b);
            else
                return leastCommonDiv(a, (b - a) / 2);
        }
    }
}

int main(){
    unsigned int a, b, T;
    std::fin >> T;

    for (int i = 0; i < T; i += 1) {
        std::fin >> a >> b;
        std::fout << leastCommonDiv(a, b) << '\n';
    }

    return 0;
}