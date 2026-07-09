Program euclid;
var i,a,b,n,r:longint;
f,g:text;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
begin
readln(f,a,b);
r:=a;
while r<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(g,a);
end;
close(f); close(f);
end.