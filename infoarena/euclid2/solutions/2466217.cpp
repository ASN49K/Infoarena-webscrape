#include <fstream>

using namespace std;

int gcd(int a, int b){
        while (a!=b){
                if(a<b) b-=a;
                if(a>b) a-=b;
        }
        return a;
}

int main() {
        ifstream in("euclid2.in");
        ofstream out("euclid2.out");
        int t;
        in>>t;
        while (t){
                int a,b;
                in>>a>>b;
                out<<gcd(a,b)<<'\n';
                --t;
        }

        return 0;
}