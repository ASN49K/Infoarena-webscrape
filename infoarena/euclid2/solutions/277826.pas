type sir=array[1..100] of longint;
const fin='euclid2.in';
      fout='euclid2.out';

var f,g:text;
    a,b:sir;
    r,n,i,aa,bb:longint;

begin
  assign(f,fin);reset(f);
  assign(g,fout);rewrite(g);
  read(f,n);
  for i:=1 to n do read(f,a[i],b[i]);
  for i:=1 to n do begin
    aa:=a[i];
    bb:=b[i];
    while bb<>0 do begin
     r:=aa mod bb;
     aa:=bb;
     bb:=r;
    end;
    writeln(g,aa)
  end;
  close(g);
end.