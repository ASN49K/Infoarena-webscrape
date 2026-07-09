var f,g:text;n,a,b,i:longint;
function cmmdc(x,y:longint):longint;
var t:longint;
begin
while b<>0 do
begin
t:=b;
b:=a mod b;
a:=t;
end;
cmmdc:=t;
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f);close(g);
end.
