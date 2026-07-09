program euclid;
var f,g:text;
n,a,b,i:longint;


function cmmdc(x,y:longint):longint;
begin
while x<>y do
if x>y then x:=x-y
else y:=y-x;
cmmdc:=x;
end;

begin
assign(f,'euclid.in');reset(f);
assign(g,'euclid.out');rewrite(g);
readln(f,n);
for i:=1 to n do
begin
read(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f);
close(g);
end.