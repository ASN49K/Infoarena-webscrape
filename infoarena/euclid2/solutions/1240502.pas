Program euclid;
Var f,g:text;
    a,b,t,i,r:longint;
Begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin
   readln(f,a,b);
   while (b <> 0) do
   begin
    r:=b;
    b:=a mod b;
    a:=r;
   end;
   write(g,a);
  end;
 close(f);
 close(g);
End.
