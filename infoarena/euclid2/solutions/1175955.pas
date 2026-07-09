var f,g:text; n,a,b,i:longint;
Procedure cmmdc(x,y:longint);
var z:longint;
begin
if x>y then begin 
            z:=x mod y;
            while z<>0 do
                        begin
                        x:=z;
                        z:=y mod z;
                        y:=x;
                        end;
            writeln(g,y);
            end
        else 
        begin 
            z:=y mod x;
            while z<>0 do
                        begin
                        y:=z;
                        z:=x mod z;
                        x:=y;
                        end;
            writeln(g,x);
            end;
end;
begin
assign(f, 'euclid2.in'); reset(f);
assign(g, 'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do 
begin
read(f,a); readln(f,b);
cmmdc(a,b);
end;
close(f); close(g);
end.