Program euclid;

Function cmmdc(a,b:longint):longint;
Var r:longint;

Begin
repeat r:=a mod b; a:=b; b:=r;
until b=0;
cmmdc:=a;
end;

Procedure tot; {specific programului}
Var i,a,b,t:longint; f,g:text;

Begin
assign(f,'euclid2.in'); reset(f); assign(g,'euclid2.out'); rewrite(g);
readln(f,t);
for i:=1 to T do
 begin
 read(f,a); readln(f,b); writeln(g,cmmdc(a,b));
 end;
close(f); close(g);
end;

Begin
tot;
end.



