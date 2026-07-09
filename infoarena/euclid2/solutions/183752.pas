program cmmdc;
var f,g:text;
    a,b,c:longint;
begin
  assign(f,'cmmdc.in');
  reset(f);
  assign(g,'cmmdc.out');
  rewrite(g);
  readln(f,a,b);
  close(f);
                while (a>0)and(b>0) do
                 begin
                   if a>b then a:=a-b
                          else b:=b-a;
                   c:=a;
                   if a=0 then c:=1;
                 end;

  writeln(g,c);
  close(g);
end.