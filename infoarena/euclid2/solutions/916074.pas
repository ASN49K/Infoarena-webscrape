program p1;
var fi,fo:text;
    i,w:longint;
    x,y,aux,max,min:longint;

function cmd(a,b:longint):longint;
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
                {   while y>0 do begin
                                 max:=x;
                                 min:=y;
                                 if y>x then begin
                                               max:=y;
                                               min:=x;
                                             end;
                                 x:=min;
                                 y:=max mod min;
                                end;
                   writeln(fo,x);
                }
                   writeln(fo,cmd(x,y));
                 end;
close(fo);
end.
