var a,b:array[1..1024] of 0..256;
    c:array[0..1024,0..1024] of byte;
    n,m,i,j:byte;

function max(x,y:byte):byte;
begin
if x>y then max:=x else max:=y;
end;

procedure afisare(x,y:byte);
begin
while a[x]<>b[y] do
if c[x-1,y]>c[x,y-1] then dec(x) else dec(y);
if c[x-1,y-1]<>0 then afisare(x-1,y-1);
write(a[x],' ');
end;

begin
assign(input,'cmlsc.in');reset(input);
assign(output,'cmlsc.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(a[i]);
for i:=1 to m do read(b[i]);
for i:=1 to n do
for j:=1 to m do
if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
else c[i,j]:=max(c[i-1,j],c[i,j-1]);
writeln(c[n,m]);
afisare(n,m);
end.


