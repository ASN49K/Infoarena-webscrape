program euclid;
var a,b,n:longint;

begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
readln(input,n);
for n:=n downto 1 do begin
readln(input,a,b);
while (a mod b<>0)and(b mod a<>0) do
if a>b then a:=a mod b
else b:=b mod a;
if a>=b then writeln(output,b) else writeln(output,a);

end;

end.