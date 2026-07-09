#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main() {
int T , a , b , i , z , x , y;
fin >> T;
for(i = 1; i <= T; i++){
    fin >> a >> b;
    x = a;
    y = b;
    while(x != y){
        if(x > y){
            x = x - y;
        }else{
        y = y - x;
        }
    }
    fout << x << "\n";
}
fout.close();
fin.close();
return 0;
}
