#include <fstream>
using namespace std;

int cmmdc(long long int a,long long int b){
    if(b==0) return a;
        else return cmmdc(b, a%b);
}

int main()
{
    ifstream in;
    in.open("euclid2.in");
    ofstream out;
    out.open("euclid2.out");

    int n;
    in >> n;
    for (int i= 0; i<n; i++){
        long long int n1, n2;
        in >> n1 >> n2;
        out << cmmdc(n1, n2) << endl;

    }
    out.close();
    in.close();
    return 0;
}
