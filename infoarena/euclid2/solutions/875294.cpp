#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <cstdlib>

using namespace std;

static inline unsigned gcd(unsigned x, unsigned y)
{
    if(!y) return x;
    return gcd(y, x%y);
}

static size_t get_file_size(const char *filename)
{
    struct stat buf;
    int rc = stat(filename, &buf);
    if( rc == -1 )
    {
        printf("stat failed\n");
        exit(0);
    }
    return buf.st_size;
}

struct FileInfo
{
    char *mem;
    int fd;
    int len;
    int pos;

    FileInfo() : mem(NULL), fd(-1), len(-1), pos(0) {}
    void map(const char *fileName)
    {
        fd = open(fileName, O_RDONLY);
        if( fd == -1 )
        {
            printf("error opening file %s\n", fileName);
            exit(0);
        }
        len = get_file_size(fileName);
        mem = (char*) mmap (NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
        madvise(mem, len, MADV_WILLNEED);
    }

    void unmap()
    {
        munmap(mem, len);
        close(fd);
    }

};

FileInfo fin;

int readNext()
{
    if(fin.pos >= fin.len)
        return -1;
    int nr = 0;
    while(fin.pos < fin.len)
    {
        if( fin.mem[fin.pos] == '\n' 
        ||  fin.mem[fin.pos] == ' ') 
            break;
        nr = nr * 10 + (fin.mem[fin.pos] - '0');
        fin.pos++;
    }
    while(fin.mem[fin.pos] == '\n' || fin.mem[fin.pos] == ' ')
        fin.pos++;
    return nr;
}

int main()
{
    fin.map("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    n = readNext();
    unsigned x, y;
    for(int i = 0; i < n; ++i)
    {
        x = readNext();
        y = readNext();
        out << gcd(x, y) << endl;
    }

    return 0;
}
