#include <iostream>
#include <fstream>

using namespace std;

long n,m, max_sum, mat[100][100], l[100];

bool sol(int k){
    return (k == n-1);
}

void backt(int k){
    for(int i = 0; i < 2; i++){
        l[k] = i;
        if(sol(k)){
            long sum = 0;
            for(int j = 0; j < m; j++){
                long s =0;
                for(int p = 0; p < n; p++)
                    if(l[p] == 0)
                        s -= mat[p][j];
                    else s += mat[p][j];
                if(s < 0)
                    sum -= s;
                else sum += s;
            }
            if(sum >= max_sum)
                max_sum= sum;
        }
        else
            backt(k+1);
    }
}

int gcd(int a, int b){
    return (b != 0) ? gcd(b, a % b) : a;
}
int a, b;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> n ;
    for(int i = 0; i < n; i++){
        in >> a >> b;
        out << gcd(a,b) << endl;
    }
}
