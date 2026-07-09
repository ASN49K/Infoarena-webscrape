Program euclid2;
Var
  f,g:Text;
  T,a,b,d,i,j,max,x:Longint;
Begin
  d:=1;j:=0;max:=0;x:=0;
  Assign(f,'euclid2.in');Reset(f);
  Assign(g,'euclid2.out');Rewrite(g);
  Readln(f,T);
  For i:=1 To T Do
    Begin
      Read(f,a,b);
      If(a>=b)
        Then max:=a
        Else max:=b;
      If(a>=b)
        Then x:=trunc(a/b)
        Else x:=trunc(b/a);
      If(a>=b) And (a>=x*b)
        Then max:=trunc(a/x);
      If(b>=a) And (b>=x*a)
        Then max:=trunc(b/x);
      d:=1;
      For j:=1 To max Do
        If(a Mod j=0) And (b Mod j=0) And (j>=d)
          Then d:=j;
      Writeln(g,d);
    End;
  Close(f);Close(g);
End.