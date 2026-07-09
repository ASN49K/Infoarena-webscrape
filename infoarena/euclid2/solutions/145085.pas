program eculid2;
var a,b:longint; f,g:text;
begin
   assign(f,'euclid2.in'); reset(f);
   assign(g,'euclid2.out'); rewrite(g);
   readln(f,a,b);
   while (b<>a) do
      if a>b then a:=a-b
             else b:=b-a;
  writeln(g,a);
  close(f); close(g);
end.
