program euclid;
var a,b,r,t:longint;
begin
  assign(input,'euclid2.in'); reset (input);
  assign(output,'euclid2.out'); rewrite(output);
  readln(t);
  repeat
    readln(a,b);
    r:=a mod b;
    while r<>0 do begin
      a:=b; b:=r; r:=a mod b;
    end;
    writeln(b);
    t:=t-1;
  until t=0;
  close(input); close(output);
end.
