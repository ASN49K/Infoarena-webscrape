#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int GCD(int A, int B){
    if(!B)
        return A;
    else
        return GCD(A, A%B);


    return 0;
}
int main()
{
    int A,B,T;
    f >> T;
    f >> A;
    f >> B;
    for (; T; --T){
        cout << GCD(A,B);
        g << B;
    }
    return 0;
}
