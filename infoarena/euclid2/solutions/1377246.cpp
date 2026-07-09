#include<fstream>

int main(){
    unsigned long a, b, t, n;
    std::ifstream in;
    std::ofstream out;
    in.open("euclid2.in");
    out.open("euclid2.out");
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a>>b;
        while (b != 0)
        {
            t = b;
            b = a % b;
            a = t;
        }
        //if(a==1)a=0;
        out<<a<<'\n';
    }
    in.close();
    out.close();
}
