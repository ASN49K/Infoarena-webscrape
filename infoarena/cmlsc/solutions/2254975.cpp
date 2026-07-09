#include <bits/stdc++.h>

using namespace std;

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
        static const int SIZE=0x20000; ///0.2MB
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
            //sign&=0;
            n=target;
            /*if (n<0)
                sign=1,
                buffer[index]='-',
                inc();
            n^=((n^-n)&-sign);*/
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
        static const int SIZE=0x10000; ///0.1MB
        int index,aux,n/*,sign*/;
        char buffer[SIZE],nr[24];
        inline void inc(){
            if(++index==SIZE)
                index&=0,output_file.write(buffer,SIZE);}
};

parser f ("cmlsc.in");
writer t ("cmlsc.out");

int m,n,d[1030][1030],bt[1030][1030],v[1030],w[1030];
vector <int> sol;

int main(){
    f>>m>>n;
    for (int i=0;i<m;++i)
        f>>v[i];
    for (int i=0;i<n;++i)
        f>>w[i];
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (d[i-1][j]>=d[i][j-1])
                d[i][j]=d[i-1][j]+(v[i]==w[j]),
                bt[i][j]=0;
            else
                d[i][j]=d[i][j-1]+(v[i]==w[j]),
                bt[i][j]=1;
    t<<d[m-1][n-1]<<"\n";
    int i=m-1,j=n-1;
    while (i>=0 and j>=0)
        if (bt[i][j]==1){
            if (d[i][j-1]<d[i][j])
                sol.push_back(v[i]);
            --j;
        }
        else{
            if (d[i-1][j]<d[i][j])
                sol.push_back(v[i]);
            --i;
        }
    for (vector<int>::iterator it=sol.end()-1;it>=sol.begin();--it)
        t<<*it<<" ";
    return 0;
}
