program euclid;
var a,b,r,t,i:longint;
    f,g:text;
function cmmdc(a,b:longint):longint;
begin
while b<> 0 do begin
               r:=b mod a;
               a:=b;
               b:=r;
            end;
cmmdc:=a;
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,t);
for i:=1 to t do
              begin
              readln(f,a,b);
              writeln(g,cmmdc(a,b));
              end;
close(f);
close(g);
end.