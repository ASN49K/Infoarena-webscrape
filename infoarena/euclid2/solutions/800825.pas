var f,g:text;
    a,b,t,i:longint;
    v1,v2:array[1..1 shl 15] of char;
begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  settextbuf(f,v1);
  settextbuf(g,v2);
  reset(f);
  rewrite(g);
  readln(f,t);
  for i:=1 to t do
    begin
      readln(f,a,b);
      while a<>b do
        if a>b then
          dec(a,b)
        else
          dec(b,a);
      writeln(g,a);
    end;
  close(f);
  close(g);
end.
