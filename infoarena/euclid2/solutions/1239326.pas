Program euclid;
Var f,g:text;
    a,b,t,i:integer;
Begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin
   readln(f,a,b);
   while (b <> 0) and (a <> 0) do
    if a > b then a:=a mod b
             else b:=b mod a;
   writeln(g,b+a);
  end;
 close(f);
 close(g);
End.