var f,g:text; t:0..100000;
    a,b,c:longint;
function euclid(x:longint;y:longint):longint;
var r:longint;
begin
r:=x mod y;
if r<>0 then euclid:=euclid(y,r)
        else euclid:=y;
end;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,t);
while t>0 do
   begin read(f,a,b); c:=euclid(a,b); t:=t-1;  writeln(g,c); end;
close(f); close(g);
end.
