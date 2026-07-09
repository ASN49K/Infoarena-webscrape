#include <fstream>
using namespace std;
ofstream out("euclid2.out");
ifstream in("euclid2.in");

long long int cmmdc(long long int a,long long int b){
    if(b==0) return a;
        else return cmmdc(b, a%b);
}

int main()
{
    int n;
    in >> n;
    for (int i= 0; i<n; i++){
        long long int n1, n2;
        in >> n1 >> n2;
        out << cmmdc(n1, n2) << endl;

    }
    return 0;
}
