program oo;
var
a,b,t:longint;
n,i:longint;
f1,f2:text;
function cm(a,b:longint):longint;
begin
if a=0 then cm:=b else cm:=cm(b,a mod b)
end;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,n);
for i:=1 to n do
begin
readln(f1,a,b);
writeln(f2,cm(a,b));
end;
close(f1);
close(f2)
end.

