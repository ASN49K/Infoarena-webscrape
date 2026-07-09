    #include <fstream>

    using namespace std;

    int lnko(int a, int b){
        int r;
        while(b != 0){
                r = a%b;
                a = b;
                b = r;
            }
            return(a);

    }

    int main() {
        ifstream in("euclid2.in");
        ofstream out("euclid2.out");

        int n,a,b;
        in >> n;
        for(int i = 0; i < n;i++){
            in >> a >> b;
            out << lnko(a,b) << "\n";
        }

        in.close();
        out.close();


    }
