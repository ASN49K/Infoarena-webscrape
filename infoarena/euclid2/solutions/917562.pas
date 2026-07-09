program p1;
var i,w,x,y:longint;
    fi,fo:text;

function cmd(a,b:longint):longint;
begin
  if b=0 then cmd:=a
         else cmd:=cmd(b, a mod b);
end;

begin
assign(fi,'euclid2.in');
reset(fi);
assign(fo,'euclid2.out');
rewrite(fo);
readln(fi,w);

for i:=1 to w do
  begin
   readln(fi,x,y);
   if x>y then writeln(fo,cmd(x,y))
          else writeln(fo,cmd(y,x));
  end;

close(fo);
end.