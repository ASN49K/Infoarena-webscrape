#include <fstream>
using namespace std;

ifstream ("euclid2.in");
ofstream ("euclid2.out");

int cmmdc(int a, int b) {

    int r;

    while(b) {

        r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

        int T,a,b;

        cin>>T;

        for(int i = 0; i<T ; i++) {

            cin>>a>>b;

            cout<<cmmdc(a,b)<<" ";
        }

        return 0;
}
