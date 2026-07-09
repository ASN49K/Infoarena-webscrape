#include <fstream>
using namespace std;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    in >> T;
    for(int i=0; i<T; i++){
        int a, b;
        in >> a >> b;
        while(a != b){
            if(a>b){
                a-=b;
            }
            else{
                b-=a;
            }
        }
        out << a << endl;
    }
}
