program cmmdivcom;
var a,b,t,i:longint;
function cmmdc(a,b:longint):longint;
begin
if a mod b=0 then cmmdc:=b
             else cmmdc:=cmmdc(b,a mod b);
end;
begin
assign(input,'euclid2.in'); reset(input);
assign(output,'euclid2.out'); rewrite(output);
readln(t);
for i:=1 to t do begin
                 readln(a,b);
                 if a>b then writeln(cmmdc(a,b))
                        else writeln(cmmdc(b,a));
                 end;
close(input);
close(output);
end.
