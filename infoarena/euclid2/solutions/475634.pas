program  euclid2;


var fin,fout:text;
    a,b,c:integer;

function alg(a,b:integer):integer;
begin

if b=0 then alg:=a
else
if a>b then alg:=alg(a-b,b)
else
alg:=alg(a,b-a);

end;


begin
assign(fin,'euclid2.in');
reset(fin);
assign(fout,'euclid2.out');
rewrite(fout);
read(fin,a);
read(fin,b);
write(fout,alg(a,b));
close(fout);
end.