var i,x,y,n,aux:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,n);
for i:=1 to n do
 begin
  readln(f,x,y);
  if x>y then begin
              aux:=x;
              x:=y;
              y:=aux;
              end;
  while x<>0 do
   begin
    aux:=y mod x;
    y:=x;
    x:=aux;
   end;
  writeln(g,y)
 end;
close(f);
close(g);
end.
