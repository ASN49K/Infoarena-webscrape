var t,i:longint;
    f,g:text;
procedure cmmdc;
var a,b,r:longint;
begin
readln(f,a,b);
r:=a mod b;
while r>0 do
begin
a:=b;
b:=r;
r:=a mod b;
end;
writeln(g,b);
end;
begin
assign(f,'euclid2.in'); reset(f);
readln(f,t);
assign(g,'euclid2.out'); rewrite(g);
for i:=1 to t do
cmmdc;
close(f); close(g);
end.