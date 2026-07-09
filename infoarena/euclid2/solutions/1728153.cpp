#include <fstream>
#include <iostream>

using namespace std;

const int table = 17;

int x, y, v[table][table], ress = - (256000000 | 1);

ifstream in ("flip.in");
ofstream out ("flip.out");

int main(){
    in >> x >> y;
    for (int i = 0; i < x; i++)
        for (int j = 0 ; j < y; j++)
            in >> v[i][j];
    for (int it = 0; it < (1 << y); ++ it){
            int SubSum = 0;
            for (int i = 0 ; i < x ; i ++ ) {
                    int S = 0;
                for (int j = 0 ; j < y ; j ++ )
                    S += ((1 << j) & it ? - v[i][j] : v[i][j]);
                    SubSum += (S < 0 ? - S : S);

            }
             ress = (SubSum > ress ?  SubSum : ress);
    }
    out << ress;
    return 0;
}
