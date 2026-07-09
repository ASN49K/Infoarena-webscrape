program euclid2;
var a,b,i,cmmdc:integer;
    t:1..100000;
    f,g:text;
begin
  assign(f,'euclid2.in');
    reset(f);
  assign(g,'euclid2.out');
    rewrite(g);
  readln(f,t);
              for i := 1 to t do
               begin
                 read(f,a,b);
                 if (a<>0) and (b<>0) then
                   begin
                     while a<>b do
                      begin
                        if a>b then a:=a-b
                               else b:=b-a;
                      end;
                     cmmdc:=a;
                   end
                                      else writeln(g);
                 writeln(g,cmmdc);
               end;
  close(f);
  close(g);
end.