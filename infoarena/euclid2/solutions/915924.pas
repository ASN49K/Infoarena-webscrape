program p1;
var fi,fo:text;
    i,w:longint;
    x,y,aux:longint;
{
function cmd(a,b:longint):longint;
begin
if b=0 then cmd:=a
             else cmd:=cmd(b,a mod b);

end;
}
begin
assign(fi,'euclid2.in');
reset(fi);
readln(fi,w);
assign(fo,'euclid2.out');
rewrite(fo);
for i:=1 to w do begin
                   readln(fi,x,y);
                   if x=y then writeln(fo,x) else begin
                   while y>0 do begin
                                 aux:=x;
                                 x:=y;
                                 y:=aux mod y;
                                end;
                   writeln(fo,x);
                                                  end;
                 end;
close(fo);
end.
