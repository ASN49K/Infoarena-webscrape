program eculid2;
var a,t,b:longint; f,g:text;
begin
   assign(f,'euclid2.in'); reset(f);
   assign(g,'euclid2.out'); rewrite(g);
   readln(f,a,b);
   while (b<>0) do begin
      t:=b;
      b:=a mod b;
      a:=t;
    end;

  writeln(g,a);
  close(f); close(g);
end.
