type vector=array[0..1024] of integer;
     matrice=array[0..1024,0..1024]of integer;
var f,g:text;
    a,b,d:vector;
    c:matrice;
    n,m,i,j,nr:integer;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do
read(f,a[i]);
readln(f);
for I:=1 to m do
read(f,b[i]);
for i:=1 to n do
        for j:=1 to m do
                if a[i]=b[j] then
                        c[i,j]:=c[i-1,j-1]+1
                else
                        if c[i-1,j]>c[i,j-1] then
                                c[i,j]:=c[i-1,j]
                        else
                                c[i,j]:=c[i,j-1];
i:=n;
J:=m;
while (i>=1) and (J>=1) do
        if a[i]=b[j] then
                begin
                inc(nr);
                d[nr]:=b[j];
                dec(i); dec(j);
                end
        else
                if c[i-1,j]>c[i,j-1] then
                        I:=i-1
                else
                        J:=j-1;
writeln(g,c[n,m]);
for i:=nr downto 1 do
write(g,d[i],' ');
close(f);
close(g);
end.
