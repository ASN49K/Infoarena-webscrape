#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int Q, N;

int main(){
    in >> Q;
    for(int i = 1; i <= Q; ++i){
        in >> N;
        int sol = 0;
        for(int j = 1; j <= N; ++j){
            int nr;
            in >> nr;
            sol ^= nr;
        }
        if(!sol)
          out << "NU \n";
        else
          out << "DA \n";
    } 
    return 0;
}
