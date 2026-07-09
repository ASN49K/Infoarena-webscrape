var i,n,nr,nr1,r:longint;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out');rewrite(output);
readln(n);
for i:=1 to n do begin
read(nr,nr1);
r:=nr mod nr1;
while r<>0 do begin
nr:=nr1;
nr1:=r;
r:=nr mod nr1; end;
writeln(nr1,' ');
end;
close(input); close(output);
end.