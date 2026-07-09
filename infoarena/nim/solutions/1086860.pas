program nim;
var t ,n,a,i,xorsum:longint;
begin

  assign(input,'nim.in'); reset(INPUT);
  assign(output,'nim.out'); rewrite(output);
  readln(T);
  while t<>0 do begin
                readln(n);
                xorsum:=0;
                for i:=1 to n do begin
                                 read(a);
                                 xorsum:=xorsum xor a;
                                 end;
                if xorsum<>0 then writeln('DA') else writeln('NU');
                dec(t);
                end;
  close(output);
end.

