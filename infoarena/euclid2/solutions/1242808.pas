program Euclid;

var
  fi, fo: text;
  a, b, i, j, n: longint;

function max (a, b: longint) : longint;
begin
  if a > b then max := a else max := b;
end;

begin
  assign(fi, 'euclid.in');
  assign(fo, 'euclid.out');
  reset(fi);
  rewrite(fo);
  readln(fi, n);
  for j := 1 to n do 
  begin
    readln(fi, a, b);
    for i := max(a, b) div 2 downto 2 do
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
