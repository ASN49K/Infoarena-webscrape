var a,b,d:longint;
begin
  assign(input,'euclid2.in'); reset(input);
  assign(output,'euclid2.out'); rewrite(output);
  readln(a,b);
  d:=a mod b;
  while d<>0 do begin
    a:=b; b:=d; d:=a mod b;
  end;
  writeln(b);
  close(input); close(output);
end.