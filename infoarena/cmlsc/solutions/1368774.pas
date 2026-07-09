program subsir_insir;
var a,b,c:array[1..256]of integer; d,na,nb,i,k,j,p:integer; f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f); rewrite(g);

readln(f,na,nb);
for i:= 1 to na do
read(f,a[i]);
readln(f);
for j:= 1 to nb do
read(f,b[j]);

k:=1;
p:=0;
if (na>1)and(nb>1)and(nb<1024)and(na<1024) then
begin
for i:= 1 to na do
 for j:= 1 to nb  do
  if (a[i]=b[j]) then begin

        if (c[k]<>a[i]) then begin
        c[p+1]:=a[i];p:=p+1; end; k:=k+1; end;

end;
writeln(g,p);
for d:= 1 to p do write(g,c[d],' ');
close(f);
close(g);

end.
