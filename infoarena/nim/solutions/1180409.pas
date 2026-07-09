var a,i,n,rs:longint;
    t:byte;
    bif,bof:array[1..1 shl 16] of char;

begin
 assign(input,'nim.in');
 assign(output,'nim.out');
 reset(input);
 rewrite(output);
 settextbuf(input,bif);
 settextbuf(output,bof);

  readln(t);

   while t>0 do
    begin
     readln(n); rs:=0;
      for i:=1 to n do
       begin
        read(a);
        rs:=rs xor a;
       end;

      if rs=0 then writeln('NU')
              else writeln('DA');
     dec(t);
    end;

 close(input);
 close(output);
{Totusi este trist in lume}
end.