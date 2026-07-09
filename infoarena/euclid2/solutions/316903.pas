program euclid;
var a,b:integer;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(input,a,b);
while a<>b do
 if a>b then a:=a-b else b:=b-a;
writeln(output,a);
close(input);
close(output);
end.