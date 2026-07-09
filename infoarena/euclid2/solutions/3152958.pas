function gcd(a,b:longint):longint;
begin
if (b=0)then gcd:=a
             else gcd:=gcd(b,a mod b);
end;


var f,g:text;a,b,i,n:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);

for i:=1 to n do begin
readln(f,a,b);
writeln(g,gcd(a,b));
end;
close(f);close(g);
end.