program euclid;
var r,a,b,t,i:longint;
begin
  assign(input,'euclid2.in'); reset(input);readln(t);
  assign(output,'euclid2.out'); rewrite(output);
  for i:=1 to t do begin
    readln(a,b);
    r:=a mod b;
    while r<>0 do begin
      a:=b; b:=r; r:=a mod b;
    end;
    writeln('b=',b);
  end;
  close(input); close(output);
  end.