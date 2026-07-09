program euclid;
var a,b:longint;
        n:word;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
readln(input,n);
while n<>0 do begin
readln(input,a,b);
while ((a mod b<>0)and(b mod a<>0)) do if a>b then a:=a mod b else b:= b mod a;
if a>=b then writeln(output,b) else writeln(output,a);
n:=n-1;
end;
close(input);
close(output);
end.