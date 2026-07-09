var i,n,a,b:longint;
    f,g:text;

function gcd(a,b:longint);
  begin
    if b=0 then gcd:=a
      else gcd:=a mod b;
  end;

begin
  assign(f,'euclid2.in');
  reset(f);
  assign(g,'euclid2.out');
  rewrite(g);
  readln(f,n);
  for i:=1 to n do begin
    readln(a,b);
    writeln(g,gcd(a,b);
  end;
  close(f);
  close(g);
end.