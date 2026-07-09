Program euclid2;
var f, g:text;
    a, b, i, x, t:longint;
begin
assign(f, 'euclid2.in');
assign(g, 'euclid2.out');
reset(f); rewrite(g);
readln(f, t);
For i:=1 to t do begin read(f, a); readln(f, b);
                       while b<>0 do begin x:=b;
                                           b:=a mod b;
                                           a:=x;
                                     end;
                       writeln(g, a);
                 end;
close(f); close(g);
end.