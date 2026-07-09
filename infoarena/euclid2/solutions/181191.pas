program euclid;
var t,n,m,i,r:longint;
    f,g:text;
begin
assign(f,'euclid2.in');assign(g,'euclid2.out');reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do begin
readln(f,n,m);
r:=n mod m;
n:=m;
m:=r;
while r<>0 do begin
r:=n mod m;
n:=m;
m:=r;end;
writeln(g,n);end;
close(f);close(g);end.