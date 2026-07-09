var f,g:text;
    a,b,i,n:longint;

procedure euclid(a,b:longint);
  begin
    if a mod b=0 then writeln(g,b) else euclid(b,a mod b);
  end;

procedure citire;
  begin
    assign(f,'euclid2.in');
    reset(f);
    assign(g,'euclid2.out');
    rewrite(g);
    readln(f,n);
    for i:=1 to n do begin
      readln(f,a,b);
      if a>b then euclid(a,b) else euclid(b,a);
    end;
    close(g);
  end;

begin
  citire;
end.