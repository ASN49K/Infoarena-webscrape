program euclid;
var f,g:text;
n,a,b,i:longint;


function cmmdc(x,y:longint):longint;
var d:longint;
begin
if y=0 then
d:=x
else d:=cmmdc(y,x mod y);
cmmdc:=d;
end;

begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do
begin
read(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(f);
close(g);
end.
