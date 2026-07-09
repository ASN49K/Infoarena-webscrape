var     t,i:longint;
        a,b:longint;
        f1,f2:text;

function cmmdc(a,b:longint):longint;
begin
  if b=0 then cmmdc:=a
  else cmmdc:=cmmdc(b,a mod b);
end;

begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);
rewrite(f2);
readln(f1,t);
for i:=1 to t do
  begin
    readln(f1,a,b);
    writeln(f2,cmmdc(a,b));
  end;
close(f1);
close(f2);
end.