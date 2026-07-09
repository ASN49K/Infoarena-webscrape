program cmmdc;
var a,b,aux:integer;
begin
read(a,b);
aux:=a; a:=b; b:=aux;
while b<>0 do
begin
aux:=a mod b ; a:=b; b:=aux; end;
writeln(a);
readln;
end.