program project1;
var f,g:text;
    a,b,i,n,aux,r:longint;
begin

assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
    begin
    readln(f,a,b);
    if a<b then
       begin
       aux:=a;
       a:=b;
       b:=aux;
       end;
    r:=1;
    while b<>0 do
        begin
        r:=a mod b;
        a:=b;
        b:=r;
        end;
    writeln(g,a);
    end;
close(f); close(g);
end.

