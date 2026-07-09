program p1;
var x,y,aux:longint;
    i,w:longint;
    fi,fo:text;

begin
assign(fi,'euclid2.in');
reset(fi);
assign(fo,'euclid2.out');
rewrite(fo);
readln(fi,w);

for i:=w downto 1 do
  begin
   readln(fi,x,y);
   repeat
     aux:=x;
     x:=y;
     y:=aux mod y;
   until y=0;
   writeln(fo,x);

  end;

close(fo);
end.