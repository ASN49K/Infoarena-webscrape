program euclid2;
var a,b,i,cmmdc:integer;
    f,g:text;
    t:1..100000;
begin
  assign(f,'euclid2.in');
  reset(f);
  assign(g,'euclid2.out');
  rewrite(g);
  readln(f,t);
              for i := 1 to t do
               begin
                 read(f,a,b);
                 if (2<=a) and (b<=2000000000) then
                  begin
                     while a<>b do
                      begin
                        if a>b then a:= a-b
                               else b:= b-a;
                      end;
                   cmmdc:=a;
                   writeln(g,cmmdc);
                 end;
               end;
  close(f);
  close(g);
end.