var f,g:text; t,i:0..100000;
    a,b:longint;
function euclid(x,y:longint):integer;
begin
if x- y=0 then writeln(g,x)
             else if x>y then euclid(x-y,y)
                         else euclid(x,y-x);
end;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
read(f,t);
for i:=1 to t do
   begin read(f,a,b); euclid(a,b); end;
close(f); close(g);
end.