var i,j,k,x,y,n,aux:longint;
begin
read(n);
for i:=1 to n do
 begin
  read(x,y);
  while y<>0 do
   begin
    aux:=y;
    y:=x mod y;
    x:=aux;
   end;
  writeln(x);
 end;
end.