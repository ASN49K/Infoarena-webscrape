var a,b,i,n:integer; f1,f2:text;
function gcd(a,b:integer):integer;
begin
        if a mod b = 0 then gcd:=b
        else gcd:=gcd(b, a mod b);
end;
begin
assign(f1,'euclid2.in');
reset(f1);
assign(f2,'euclid2.out');
rewrite(f2);
readln(f1,n);
for i:=1 to n do begin
readln(f1,a,b);
writeln(f2,gcd(a,b));
end;
close(f1);
close(f2);
end.
