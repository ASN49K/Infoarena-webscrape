var n,t,i,j,x,s:longint;
f,g:text;
begin
assign(f,'nim.in');
assign(g,'nim.out');
reset(f);rewrite(g);
readln(f,t);
for i:=1 to t do
    begin
    read(f,n);
    s:=0;
    for j:=1 to n do
        begin
        read(f,x);
        s:=s xor x;
        end;
    if s=0 then
       writeln(g,'NU')
    else
        writeln(g,'DA');
    end;
close(f);close(g);
end.