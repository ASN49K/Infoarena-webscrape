program euclid2;
var     i,aux,t,x,y,a,b,r:longint;
        bufin,bufout:array[1..65355]of byte;

begin
  assign(input,'euclid2.in'); reset(input);
  assign(output,'euclid2.out'); rewrite(output);
  settextbuf(input,bufin);
  settextbuf(output,bufout);
  readln(t);
  for i:=1 to t do
    begin
      readln(x,y);
      r:=1;
      if x<y then
        begin
          aux:=x;
          x:=y;
          y:=aux;
        end;
      while r<>0 do
        begin
          r:=x mod y;
          x:=y;
          y:=r;
        end;
      writeln(x);
    end;
  close(input); close(output);
end.