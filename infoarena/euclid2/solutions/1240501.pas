Program euclid;
Var f,g:text;
    a,b,t,i:longint;
Function cmmdc(a,b:longint):longint;
 Var r:longint;
 Begin
  while (b <> 0) do
   begin
    r:=b;
    b:=a mod b;
    a:=r;
   end;
  cmmdc:=a;
 End;
Begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin
   readln(f,a,b);
   writeln(g,cmmdc(a,b));
  end;
 close(f);
 close(g);
End.
