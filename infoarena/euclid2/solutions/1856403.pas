Program vv;
var f,g:Text;
    a,b,t,i:Longword;
Begin
 Assign (f,'euclid2.in');reset (f);
 Assign (g,'euclid2.out');Rewrite (g);
 Readln (f,t);
 for i:=1 to t do
 Begin
  Read (f,a,b);
  While a<>b do
  If a>b then a:=a-b
  Else b:=b-a;
  Writeln (g,a);
 End;
 Close (f);Close (g);
End.
