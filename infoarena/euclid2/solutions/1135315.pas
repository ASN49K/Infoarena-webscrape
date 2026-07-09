Program Algo;
 Var f,g : text;
     t, a, b :qword;
     i : integer;
Procedure Divizor(x, y : qword);
 Begin
   If x=y then
            A:=x
           else
            begin
            if x<y then
                     Divizor(x, y-x)
                    else
                      Divizor(y, x-y);
            end;
 End;

Begin
  Assign(f,'euclid2.in');
   Reset(f)  ;
 Assign(g,'euclid2.out');
 Rewrite(g);
 Read(f, t);
 For i:=1 to t Do
 begin
  Readln(f, a, b);
   Divizor(a,b);
  writeln(g,a);
 End;
 Close(f);
 Close(g);
End.
