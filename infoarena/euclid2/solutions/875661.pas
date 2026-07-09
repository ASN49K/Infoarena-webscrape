var x,y,t:int64;
    f,fo:text;
    ta:longint;
    i:longint;
    bufin,bufout:array[1..65000]of byte;
  
  
begin
  
  
assign(f,'euclid2.in');reset(f);
readln(f,t);
assign(fo,'euclid2.out');
rewrite(fo);

settextbuf(f,bufin);
settextbuf(fo,bufout);
  
for i := 1 to t do
begin
readln(f,x,y);
  
//if (x=0)or (y=0) then writeln(fo,'0')
//else
begin
  
{if x <> y then
repeat
  if x<y then
    y := y -x
  else
    x := x - y;
until x=y ;
writeln(fo,x);}
  x :=x mod y;
  
  while x <> 0  do
  begin
     
    ta := y mod x;
    y := x;
    x := ta;
  end;
  
  writeln(fo,y);
end;
end;
  
  
  
close(fo);close(f);
  
  
end.