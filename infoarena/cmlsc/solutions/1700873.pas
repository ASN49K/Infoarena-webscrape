program cmlsc;
var be,ki:text;
    a,b,v:array[1..1024] of byte;
    x:array[0..1024,0..1024] of byte;
    i,j,m,n:integer;

begin
        assign(be,'cmlsc.in');reset(be);
        assign(ki,'cmlsc.out');rewrite(ki);
        read(be,m);readln(be,n);
        for i:=1 to m do
                read(be,a[i]);
        for i:=1 to n do
                read(be,b[i]);

        for i:=1 to m do
                for j:=1 to n do
                        if a[i]=b[j] then
                                x[i][j]:=x[i-1][j-1] + 1
                        else
                                if x[i][j-1]>x[i-1][j] then x[i][j]:=x[i][j-1]
                                else x[i][j]:=x[i-1][j];


        i:=m;j:=n;
        while (i>0) or (j>0) do begin
                if x[i-1][j]=x[i][j] then i:=i-1
                else if x[i][j-1]=x[i][j] then j:=j-1
                else begin v[x[i][j]]:=a[i];
                           i:=i-1;
                           j:=j-1;
                           end;end;

        writeln(ki,x[m][n]);
        for i:=1 to x[m][n] do
               write(ki,v[i],' ');

        close(be);close(ki);
end.
