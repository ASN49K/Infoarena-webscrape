var f,g:text;
a,b,t,i,c:longint;

begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,t);
 for i:= 1 to t do
  begin
   readln(f,a,b);
   while b<>0 do
    begin
     c:= a mod b;

     a:= b;
     b:= c;
    end;
   writeln(g,a);
  end;
  close(f);
  close(g);
end.