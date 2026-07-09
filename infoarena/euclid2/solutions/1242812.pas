program Euclid;

var
  fi, fo: text;
  a, b, i, j, n: longint;

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
    for i := max(a, b) downto 1 do
      if ( (a mod i) = 0) and ( (b mod i) = 0) then
      begin
        writeln(fo, i);
        flush(fo);
        break;
      end;
  end;
  close(fo);
  close(fi);
end.
