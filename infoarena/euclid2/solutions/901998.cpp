#include <fstream>
 
using namespace std;
 
long CMMDC(long a, long b);
 
int main (int argc, char *argv[]){
    long numA, numB;
    int T;
    ifstream inFILE("euclid2.in");
    ofstream outFILE("euclid2.out");
    inFILE >> T;
    for (int i = 1; i <= T; i++){
        inFILE >> numA >> numB;
        outFILE << CMMDC(numA,numB) << "\n";
    }
    return 0;
}
 
long CMMDC(long a, long b){
    if (b == 0)
        return a;
    else
        return CMMDC(b,a%b);
}