program euclid2;
var a,b,n,i,cmmdc:integer;
    f,g:text;
begin
  assign(f,'euclid2.in');
  reset(f);
  assign(g,'euclid2.out');
  rewrite(g);
  readln(f,n);
              for i := 1 to n do
               begin
                 read(f,a,b);
                   while a<>b do
                    begin
                      if a>b then a:= a-b
                             else b:= b-a;
                    end;
                 cmmdc:=a;
                 writeln(g,cmmdc);
               end;
  close(f);
  close(g);
end.