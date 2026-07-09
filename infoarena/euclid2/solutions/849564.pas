Var f,g:text;
    a,b,n,i:longint;

function cmmdc(a,b:longint):longint;
var r:longint;
Begin
r:=1;
while r<>0 do
  begin
    r:=a mod b;
    a:=b;
    b:=r;
  end;
cmmdc:=a;
End;

Begin
assign(f, 'euclid2.in');reset(f);
assign(g, 'euclid2.out');rewrite(g);
read(f, n);
for i:=1 to n do
  begin
    read(f, a,b);
    writeln(g, cmmdc(a,b));
  end;
close(f);
close(g);
End.