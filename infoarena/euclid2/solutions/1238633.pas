program plm;
var f,g:text;
    a,b:integer;

function cmmdc(a,b:integer):integer;
         var r:integer;
         begin
         if a<b then r:=a
                else r:=b;
         while a mod b <>0 do begin
          r:=a mod b;
          a:=b;
          b:=r;
         end;
         cmmdc:=r;
         end;


begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a);
while not eof(f) do begin
read(f,a);read(f,b);
writeln(g,cmmdc(a,b));end;
close(f); close(g);
readln;
end.
