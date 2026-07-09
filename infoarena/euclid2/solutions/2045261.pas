Program euclid2;
var f, g:text;
    a, b, c, j:longint;
    i, t:integer;
begin
assign(f, 'euclid2.in');
assign(g, 'euclid2.out');
reset(f); rewrite(g);
readln(f, t);
For i:=1 to t do begin read(f, a); readln(f, b);
                       if a>b then c:=a
                              else c:=b;
                       For j:=c downto 1 do if (a mod j=0) and (b mod j=0) then begin writeln(g, i);
                                                                                      break;
                                                                                end;

                 end;
close(f); close(g);
end.