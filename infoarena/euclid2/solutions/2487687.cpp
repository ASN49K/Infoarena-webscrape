#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("euclid2.in");
    ofstream out;
    out.open("euclid2.out");

    int n;
    in >> n;
    for (int i= 0; i<n; i++){
        int n1, n2;
        in >> n1 >> n2;
        while(n1%n2!=0 && n2%n1!=0)
            if(n1>=n2) n1%=n2; else n2%=n1;
        if(n1>n2) n1=n2;
        out << n1 << endl;

    }
    out.close();
    in.close();
    return 0;
}
