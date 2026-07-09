#include <fstream>;
using namespace std;


/*int cmmdcBrut(int a, int b){
    int i = min(a,b);
    for (i; i>0; i--){
        if((a % i == 0) && (b % i == 0)){
            break;
        }
    }
    return i;
}

int cmmdcScaderi(int a, int b){
    while (a != b){
        if (a > b){
            a = a - b;
        } else
        {
            b = b - a;
        }

    }

    return a;

}
*/
int cmmdcImpartiri(int a, int b){
    if (b == 0) return a;
    return cmmdcImpartiri(a, a % b);

}

int main(){
    int n,a,b;
    ifstream inputfile("euclid2.in");
    ofstream outputfile("euclid2.out");
    inputfile >> n;
    for (int i = 0; i<n; i++) {
        inputfile >> a >> b;
        outputfile << cmmdcImpartiri(a,b)<< endl;
    }

    return 0;

}
