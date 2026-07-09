#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b){
    int t;
    while ( b!=0){
        t=b;
        b = a%b;
        a = t;
    }
    return a;
}


int main()
{

    int t;
    in >> t;
    for (int i= 0; i<t; i++){
        int a, b;
        in >> a >> b;
        out << euclid(a, b) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
