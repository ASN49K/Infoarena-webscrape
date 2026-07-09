var f,g:text;
n,a,b,i:integer;

function euclid(c,d:integer):integer;
var x:integer;
begin

if d mod c<>0 then begin

repeat
x:=d mod c;
d:=c;
c:=x;
until d mod c=0;
euclid:=x;
end else euclid:=c;
end;


begin
assign(g,'euclid2.out');
rewrite(G);
assign(f,'euclid2.in');
reset(f);
readln(f,n);
for i:=1 to n do
begin
readln(f,a,b);
if a<b then writeln(g,euclid(A,b)) else writeln(g,euclid(b,a));
end;
close(f);
close(g);
end.