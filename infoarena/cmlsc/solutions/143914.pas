var c : array [0..1024,0..1024] of integer;
    a,b,q : array [1..1024] of byte;
    f,g : text;
    i,j,p,m,n : integer;
function max(a,b:integer):integer;
begin
if a>b then max := a
        else max := b;
end;

begin
assign(f,'cmlsc.in');
reset(f);
readln(f,m,n);
for i := 1 to m do
read(f,a[i]);
for i := 1 to n do
read(f,b[i]);
close(f);
for i := 1 to m do
for j := 1 to n do
if a[i]=b[j] then c[i,j] := c[i-1,j-1]+1
             else c[i,j] := max(c[i-1,j],c[i,j-1]);


p := C[m,n];
i := m;
j := n;


while (i>0) and (j>0) do
begin
        if a[i]=b[j] then
        begin
        q[p] := b[j];
        dec(i);
        dec(j);
        dec(p);
        end
        else if c[i,j]=c[i-1,j] then dec(i)
                                else dec(j);
        end;

assign(f,'cmlsc.out');
rewrite(f);
writeln(f,c[m,n]);
for i := 1 to c[m,n] do
write(f,q[i],' ');
close(f);
end.
