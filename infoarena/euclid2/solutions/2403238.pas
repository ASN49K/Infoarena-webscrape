var a,b,n,i,j,k:longint;
function euclid(a,b:longint):longint;
var aux:longint;
begin
aux:=a mod b;
while aux<>0 do begin
a:=b;
b:=aux;
aux:=a mod b end;
euclid:=b
end;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(n);
for i:=1 to n do begin
read(a,b);
writeln(euclid(a,b)) end;
close(input);
close(output); end.