var i,j,k,x,y,n,aux:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,n);
for i:=1 to n do
 begin
  read(f,x,y);
  while y<>0 do
   begin
    aux:=y;
    y:=x mod y;
    x:=aux;
   end;
  writeln(g,x);
 end;
close(f);
close(g);
end.
