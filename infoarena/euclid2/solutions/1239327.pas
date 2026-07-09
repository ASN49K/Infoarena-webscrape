Program euclid;
Var f,g:text;
    a,b,t,i:longint;
Function cmmdc(a,b:longint):longint;
 Begin
  while (b <> 0) and (a <> 0) do
   if a > b then a:=a mod b
            else b:=b mod a;
   cmmdc:=b+a;
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