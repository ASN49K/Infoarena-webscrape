var r,i,n,a,b:integer;
begin
assign(input,'euclid2.in');reset(input);
assign(output,'euclid2.out');rewrite(output);
readln(n);
for i:= 1 to n do begin
readln (a,b);
repeat
r:=a mod b;
a:=b;
b:=r;
until b = 0;
writeln(a);
end;
close(input);
close(output);
end.