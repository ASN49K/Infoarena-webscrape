program p1;
var fi,fo:text;
    i,w:int64;
    x,y:int64;

function cmd(a:int64; b:int64):int64;
begin
if b=0 then cmd:=a
             else cmd:=cmd(b,a mod b);

end;
begin
assign(fi,'euclid2.in');
reset(fi);
readln(fi,w);
assign(fo,'euclid2.out');
rewrite(fo);
for i:=1 to w do begin
                   readln(fi,x,y);
                   if x>y then writeln(fo,cmd(x,y))
                          else writeln(fo,cmd(y,x));
                 end;
close(fo);
end.
