Program Algo;
 Var f,g : text;
      a, b :longword;
     t,i:longint;
Begin
  Assign(f,'euclid2.in');
   Reset(f)  ;
 Assign(g,'euclid2.out');
 Rewrite(g);
 Read(f, t);
 For i:=1 to t Do
 begin
  Readln(f, a, b);
  while A<>b do
  begin
        if a<b then
                     B:=b-a
                    else
                     a:=A-b;
 end;
  writeln(g,a);
 End;
 Close(f);
 Close(g);
End.
