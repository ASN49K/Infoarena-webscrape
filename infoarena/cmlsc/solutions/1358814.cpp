#include <fstream>
#include <vector>


using namespace std;

    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int A[1025],B[1025],C[1025][1025];
    int M,N;
    vector<int> D;
    int pos;

    int maxi(int a , int b){
        if(a>b){
            return a;
        }
        return b;


    }

    void beolvas(){
        in >> M >> N;
        for(int i = 1;i<=M;++i){
            in >> A[i];
        }
        for(int i = 1;i<=N;++i){
            in >> B[i];
        }
    }

    void betolt(){
        for(int i = 1;i<=M;i++){
            for(int j = 1 ; j<=N;j++){
                if(A[i] == B[j]){
                    C[i][j] = C[i-1][j-1] + 1;
                }else{
                    C[i][j] = maxi(C[i-1][j],C[i][j-1]);
                }
            }
        }

    }
    void kiir(){
       out << pos;
       out << endl;
        for(int i = pos-1;i>=0;i--){
            out << D[i] << " ";
        }


    }

    void megold(){
        int i = M;
        int j = N;
        pos = 0;
        while(i!=0){
            if(A[i] == B[j]){
                D.push_back(A[i]);
                pos++;
                i--;j--;

            }else if(C[i-1][j] < C[i][j-1]){
                --j;
            }else{
                --i;
            }


        }

    }







    int main(){
        beolvas();
        betolt();
        megold();
        kiir();



    }
