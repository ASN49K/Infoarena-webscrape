program Euclid;

var
  fi, fo: text;
  a, b: longint;
  i: integer;

function max (a, b: longint) : longint;
begin
  if a > b then Result := a else Result := b;
end;

begin
  assign(fi, 'euclid.in');
  assign(fo, 'euclid.out');
  reset(fi);
  rewrite(fo);
  while not eof(fi) do
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
