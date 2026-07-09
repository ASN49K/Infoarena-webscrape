#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in >> t;
    while(t--){
        int n, s = 0;
        in >> n;
        for(int i = 0; i < n; i++){
            int a;
            in >> a;
            s ^= a;
        }
        if(s){
            out << "DA\n";
        }
        else{
            out << "NU\n";
        }
    }
    return 0;
}
