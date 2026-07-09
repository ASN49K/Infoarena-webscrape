program infoarena;
var f,g:text;
    n:longint;
    a,b,i:integer;

function cmmdc(a,b:integer):integer;
var aux,r:integer;
begin
if a<b then
        begin
        aux:=a;
        a:=b;
        b:=aux;
        end;
while r<>0 do
        begin
        r:=a mod b;
        a:=b;
        b:=r;
        end;
end;

begin
assign (f, 'euclid2.in' ); reset(f);
assign (g, 'euclid2.out' ); rewrite(g);
read(f,n);
for i:=1 to n do
read(f,a); read(f,b);
writeln(g,cmmdc(a,b));
end.
