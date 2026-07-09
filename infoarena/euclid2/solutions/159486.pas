program euclid;
uses crt;
var t,a,b,i:longint;
    f,g:text;
function cmmdc(a,b:longint):longint;
begin if a=0 then cmmdc:=b
      else
           while b<>0 do
                 if a>b then a:=a-b
                 else b:=b-a;
      cmmdc:=a
end;
procedure citire;
begin assign(f,'euclid.in');reset(f);
      assign(g,'euclid.out');rewrite(g);
      readln(f,t);
      for i:=1 to t do begin
          readln(f,a,b);
          writeln(g,cmmdc(a,b));
      end;
end;
begin citire;
      close(g)
end.
