program p1;
var x,y:longint;
    i,w:integer;
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
   writeln(fo,cmd(x,y))
  end;

close(fo);
end.