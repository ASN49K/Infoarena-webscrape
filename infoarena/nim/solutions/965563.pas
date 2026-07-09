program nim;
  var bufin,bufout:array[1..100000] of byte;
      t,n,i,j,x,s:longint;

begin
  assign(input,'nim.in');
  reset(input);
  settextbuf(input,bufin);
  assign(output,'nim.out');
  rewrite(output);
  settextbuf(output,bufout);

  readln(t);
  for i:=1 to t do
    begin
      readln(n);
      s:=0;
      for j:=1 to n do
        begin
          read(x);
          s:=s xor x;
        end;
      if s=0 then writeln('NU') else writeln('DA');
    end;
  close(output);
end.