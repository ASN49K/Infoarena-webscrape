var i,j,k,m,n,aux:longint;
    f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,k);
for i:=1 to k do
 begin
  read(f,n,m);
  while m<> 0 do
   begin
     n:=n mod m;
     aux:=n;
     n:=m;
     m:=aux;
   end;
  writeln(g,n);
 end;
close(f);
close(g);
end.