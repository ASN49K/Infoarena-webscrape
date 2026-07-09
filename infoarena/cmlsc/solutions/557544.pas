var a, b, rez:array[1..1024] of integer;
    v:array[0..1024, 0..1024] of integer;
    m, n, i, ii, j:integer;
    f, g:text;

function max (aa, bb:integer):integer;
  begin if aa>bb then max:=aa else max :=bb; end;

begin
assign (f, 'cmlsc.in'); reset (f);
assign (g, 'cmlsc.out'); rewrite (g);

read (f, n, m);
for i := 1 to n do read (f, a[i]);
for i := 1 to m do read (f, b[i]);

for i := 1 to n do
  begin
  for j := 1 to m do
    begin
    if a[i]=b[j] then
      begin
      v[i, j]:=v[i-1, j-1]+1;
      end
                 else v[i, j]:=max(v[i-1, j], v[i, j-1]);
    end;
  end;

writeln (g, v[n, m]);

i:=n; j:=m;
for ii := v[n, m] downto 1 do
  begin
  while v[i, j] = v[i, j-1] do j:=j-1;
  while v[i, j] = v[i-1, j] do i:=i-1;
  rez[ii]:=a[i];
  i:=i-1;
  end;
for i := 1 to v[n, m] do write (g, rez[i], ' ');


close (f); close (g);
end.
