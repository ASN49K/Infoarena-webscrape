var a,b,r:int64;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out'); rewrite(output);
read(a,b);
r:=a mod b;
while r<>0 do begin
a:=b;
b:=r;
r:=a mod b;
end;
writeln(b);
close(input); close(output);
end.
