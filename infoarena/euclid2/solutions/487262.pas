var f,g:Text;
    i,n,p,l:longint;
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

begin
assign(f,'euclid.in');
reset(f);
assign(g,'euclid.out');
rewrite(g);
read(f,n);
for i:=1 to n do
    begin
    read(f,p,l);
    writeln(g,cmmdc(p,l));
    end;
close(f);
close(g);
end.