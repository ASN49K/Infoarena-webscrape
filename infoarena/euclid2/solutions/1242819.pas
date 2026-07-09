program Euclid;

var
  fi, fo: text;
  a, b, i, j, n: longint;

function max (a, b: longint) : longint;
begin
  if a > b then max := a else max := b;
end;

begin
  assign(fi, 'euclid2.in');
  assign(fo, 'euclid2.out');
  reset(fi);
  rewrite(fo);
  readln(fi, n);
  for j := 1 to n do
  begin
    readln(fi, a, b);
    while b <> 0 do
    begin
      j := a mod b;
      a := b;
      b := j;
    end;
    writeln(fo, a);
  end;
  close(fo);
  close(fi);
end.
