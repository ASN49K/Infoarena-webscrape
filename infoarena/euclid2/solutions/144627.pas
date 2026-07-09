var a,b:longint;

function cmmdc(a,b:longint):longint;
begin
if b=0 then
        cmmdc:=a
else
        cmmdc:=cmmdc(b,a mod b);
end;

begin
assign(input,'euclid2.in');reset(input);
assign(output,'euclid2.out');rewrite(output);
readln(a,b);
writeln(cmmdc(a,b));
close(input);close(output);
end.