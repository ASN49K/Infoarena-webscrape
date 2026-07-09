Program euclid;
Var f,g:text;
    a,b,t,i,r:longint;
Function cmmdc(a,b:longint):longint;
 Begin
  if b = 0 then cmmdc:=a
           else cmmdc:=cmmdc(b,a mod b);
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
