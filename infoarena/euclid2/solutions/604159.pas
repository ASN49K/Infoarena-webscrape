program cmmdc;
var a,b,t,i:longint;
    f,g:text;
begin
assign (f,'euclid2.in'); reset (f);
assign (g,'euclid2.out'); rewrite (g);
readln (f,t);
for i:=1 to t do begin readln (f,a,b);
                       while (a<>b) do if (a>b) then a:=a-b
                                                else b:=b-a;
                       writeln (g,a);
                 end;
close (f);
close (g);
end.
