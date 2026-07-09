var f,g:text;
    n,a,b,i:longint;

function cmmdc(a,b:longint):longint;
Begin
If a mod b=0 then cmmdc:=b
             else cmmdc:=cmmdc(b,a mod b);
end;

Begin
Assign(f,'euclid2.in');Reset(f);
Assign(g,'euclid2.out');Rewrite(g);
Readln(f,n);
For i:=1 to n do
 Begin
  Readln(f,a,b);
  Writeln(g,cmmdc(a,b));
 end;
Close(f);
Close(g);
end.