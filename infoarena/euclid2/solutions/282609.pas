var f,g:text;
function cmmdc(a,b:longint):longint;
var r:longint;
begin
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
cmmdc:=a;
end;
procedure euclid2;
var a,b,i,n:longint;
begin
assign(f,'euclid2.in');
reset(f);
readln (f,n);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f);
close(g);
end;
begin
euclid2;
end.
