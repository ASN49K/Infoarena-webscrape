#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <cstring>

using namespace std;

#define INF 0x8000

class parser{
    public:
        parser() {}
        parser(const char *file_name){
            input_file.open(file_name,ios::in | ios::binary);
            input_file.sync_with_stdio(false);
            index&=0;
            input_file.read(buffer,SIZE);}
        inline parser &operator >>(int &n){
            for (;buffer[index]<'0' or buffer[index]>'9';inc());
            n&=0;
            //sign&=0;
            //sign|=(buffer[index-1]=='-');
            for (;'0'<=buffer[index] and buffer[index]<='9';inc())
                n=(n<<1)+(n<<3)+buffer[index]-'0';
            //n^=((n^-n)&-sign);
            return *this;}
        ~parser(){
            input_file.close();}
    private:
        fstream input_file;
        static const int SIZE=0x400000; ///4MB
        char buffer[SIZE];
        int index/*,sign*/;
        inline void inc(){
            if(++index==SIZE)
                index=0,input_file.read(buffer,SIZE);}
};

class writer{
    public:
        writer() {};
        writer(const char *file_name){
            output_file.open(file_name,ios::out | ios::binary);
            output_file.sync_with_stdio(false);
            index&=0;}
        inline writer &operator <<(int target){
            aux&=0;
            sign&=0;
            n=target;
            if (n<0)
                sign=1,
                buffer[index]='-',
                inc();
            n^=((n^-n)&-sign);
            if (!n)
                nr[aux++]='0';
            for (;n;n/=10)
                nr[aux++]=n%10+'0';
            for(;aux;inc())
                buffer[index]=nr[--aux];
            return *this;}
        inline writer &operator <<(const char *target){
            aux&=0;
            while (target[aux])
                buffer[index]=target[aux++],inc();
            return *this;}
        ~writer(){
            output_file.write(buffer,index);output_file.close();}
    private:
        fstream output_file;
        static const int SIZE=0x200000; ///2MB
        int index,aux,n,sign;
        char buffer[SIZE],nr[24];
        inline void inc(){
            if(++index==SIZE)
                index&=0,output_file.write(buffer,SIZE);}
};

parser f ("euclid2.in");
writer t ("euclid2.out");

inline int euclid(int a,int b){
    int c;
    while (b)
        c=a%b,
        a=b,
        b=c;
    return a;
}

int main()
{
    int q;
    f>>q;
    for (int a,b;q;--q)
        f>>a>>b,
        t<<euclid(a,b)<<"\n";
    return 0;
}
