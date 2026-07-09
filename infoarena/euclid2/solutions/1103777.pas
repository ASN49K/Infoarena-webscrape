var c,d:longint;
m,n,r:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(c);
for d:=1 to c do
begin
    read(m);
    read(n);
    while n>0 do
    begin
        r:=m mod n;
        m:=n;
        n:=r;
    end;
    writeln(m);
end;
end.
