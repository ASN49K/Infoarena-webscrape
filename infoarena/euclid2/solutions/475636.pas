program  euclid2;


var fin,fout:text;
    a,b,t,i:integer;

function alg(a,b:integer):integer;
begin

if b=0 then alg:=a
else
alg:=alg(b,a MOD b);

end;


begin
assign(fin,'euclid2.in');
reset(fin);
assign(fout,'euclid2.out');
rewrite(fout);
read(fin,t);

for i:=1 to t do
begin
read(fin,a);
read(fin,b);
writeln(fout,alg(a,b));
end;
close(fout);
end.