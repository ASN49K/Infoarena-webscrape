program cmlsc;
type vect = array [1..1024] of byte;
var A,B,C,S : vect;
    i,j,m,n,im,l,e : integer;
    f : text;
begin
assign(f,'cmlsc.in');
reset(f);

readln(f,m,n);

for i := 1 to m do
read(f,A[i]);
readln(f);
for i := 1 to n do
read(f,B[i]);

close(f);

im := 0;
for i := 1 to n do begin
e := 0;
for j := i to n do
for l := 1 to m do
if B[j]=A[l] then begin
                  e := e+1;
                  C[e] := B[j];
                  end;
if e>im then begin
                im := e;
                S := C;
                end;
end;

assign(f,'cmlsc.out');
rewrite(f);

writeln(f,im);
for i := 1 to im do
write(f,S[i],' ');

close(f);
end.