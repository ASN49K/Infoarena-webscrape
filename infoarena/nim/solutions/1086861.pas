program nim;
var t ,n,a,i,xorsum:longint;
    buf1,buf2:array[1..1 shl 16] of char;
begin

  assign(input,'nim.in'); settextbuf(input,buf1); reset(INPUT);
  assign(output,'nim.out');settextbuf(output,buf2); rewrite(output);
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

