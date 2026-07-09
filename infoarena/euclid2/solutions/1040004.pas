program euclid;
var t,n,m,i:longint;
function cmmdc(a,b:longint):longint;
begin
  if a mod b=0 then cmmdc:=b
    else cmmdc:=cmmdc(b,a mod b);
end;
begin
assign(input,'euclid2.in');
reset(input);
assign(output,'euclid2.out');
rewrite(output);
readln(t);
for i:=1 to t do begin
    readln(n,m);
    if n>m then writeln(cmmdc(m,n))
        else writeln(cmmdc(n,m));
        end;
close(output);
end.
