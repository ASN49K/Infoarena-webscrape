#include <iostream>
#include <fstream>

/**

                .,aadd"'    `"bbaa,.
            ,ad8888P'          `Y8888ba,
         ,a88888888              88888888a,
       a88888888888              88888888888a
     a8888888888888b,          ,d8888888888888a
    d8888888888888888b,_    _,d8888888888888888b
   d88888888888888888888888888888888888888888888b
  d8888888888888888888888888888888888888888888888b
 I888888888888888888888888888888888888888888888888I
,88888888888888888888888888888888888888888888888888,
I8888888888888888PY8888888PY88888888888888888888888I
8888888888888888"  "88888"  "88888888888888888888888
8::::::::::::::'    `:::'    `:::::::::::::::::::::8
Ib:::::::::::"        "        `::::::' `:::::::::dI
`8888888888P            Y88888888888P     Y88888888'
 Ib:::::::'              `:::::::::'       `:::::dI
  Yb::::"                  ":::::"           "::dP
   Y88P                      Y8P               `P
    Y'                        "
                                `:::::::::::;8"
       "888888888888888888888888888888888888"
         `"8;::::::::::::::::::::::::::;8"'
            `"Ya;::::::::::::::::::;aP"'
                ``""YYbbaaaaddPP""''
**/

using namespace std;

class parser{
    public:
        parser() {}
        parser(const char *file_name){
            input_file.open(file_name,ios::in | ios::binary);
            input_file.sync_with_stdio(false);
            index=0;
            input_file.read(buffer,SIZE);}
        inline parser &operator >>(int &n){
            for (;buffer[index]<'0' or buffer[index]>'9';inc());
            n=0;
            for (;'0'<=buffer[index] and buffer[index]<='9';inc())
                n=10*n+buffer[index]-'0';
            return *this;}
        ~parser(){
            input_file.close();}
    private:
        fstream input_file;
        static const int SIZE=0x8000;
        char buffer[SIZE];
        int index=0;
        inline void inc(){
            if(++index==SIZE)
                index=0,input_file.read(buffer,SIZE);}
};

parser f ("nim.in");
ofstream t ("nim.out");

int main()
{
    int q;
    f>>q;
    for (int n,i=0;i<q;++i){
        f>>n;
        int xorsum=0;
        for (int aux,i=0;i<n;++i){
            f>>aux;
            xorsum^=aux;
        }
        if (xorsum)
            t<<"DA"<<'\n';
        else
            t<<"NU"<<'\n';
    }
    return 0;
}
