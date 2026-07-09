var a,b,r,t,i:longint;
    f,g:text;

Function cmmdc(a,b:longint):longint;
  Begin
       If a=b then cmmdc:=1
              else  if a>b then cmmdc:=cmmdc(a-b,b)
                           else cmmdc:cmmdc(a,b-a);
   End;

begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
r:=cmmdc(a,b);
writeln(g,r);
end;
close(f);close(g);
end.