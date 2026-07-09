program Euclid;

var
  fi, fo: text;
  a, b, i, j, n: longint;

function min(a, b: longint) : longint;
begin
  if a > b then min := b else min := a;
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
    for i := min(a, b) div 2 downto 2 do
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
