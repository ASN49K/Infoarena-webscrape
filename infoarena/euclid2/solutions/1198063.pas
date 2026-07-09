var a,b,n,i:word;
    f,g:text;
procedure divz(a,b:longint);
var r:longint;
begin
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(g,a);
end;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n);
repeat
read(f,a,b);
divz(a,b);
i:=i+1;
until i=n;
close(F);
close(G);
end.