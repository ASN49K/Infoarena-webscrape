#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;

    //Input File
    ifstream in;
    in.open("euclid2.in");
    in >> n;
    /////////////

    int a;
    int b;

    int A[n];
    int B[n];

    int r = 0;

    for(int i = 1; i<=n;++i){
        in >> a >> b;
        A[r] = a;
        B[r] = b;
        r += 1;
    }

    int cmmdc;

    //Output File
    ofstream out("euclid2.out");
    /////////////

    for(int i = 0;i<n;++i){
        cmmdc = A[i];
        while(A[i] % cmmdc + B[i] % cmmdc != 0){
            cmmdc -= 1;
        }
        out << cmmdc << endl;
    }
}
