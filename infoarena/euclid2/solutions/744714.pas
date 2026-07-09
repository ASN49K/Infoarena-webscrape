var a,b,i,r,t:longint;
   b1,b2:array[1..1 shl 17] of char;
Begin
  assign(input,'euclid2.in');
  settextbuf(input,b1);
  reset(input);
  assign(output,'euclid2.out');
  settextbuf(output,b2);
  rewrite(output);
  read(t);
  for i:=1 to t  do
    begin
      read(a,b);
      r:=a mod b;
      while r<>0 do
      begin
        a:=b;
        b:=r;
        r:=a mod b;
      end;
    writeln(b);
  end;
Close(input);
close(output);
end.


