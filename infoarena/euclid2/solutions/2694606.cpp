#include <iostream>
#include <fstream>

using namespace std;
ifstream c("euclid2.in");
ofstream f("euclid2.out");
int main()
{
    int T,A,B,R;
    c >> T;
    for(int i = 0; i < T; i++){
        c >> A >> B;
        while(B!=0){
            R = A % B;
            A = B;
            R = B;
        }
        f << A << "\n";
    }
    return 0;
}
