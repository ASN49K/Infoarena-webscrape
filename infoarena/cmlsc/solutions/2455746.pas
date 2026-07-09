type vector = array[1..1024,1..1024] of integer;
var x:vector;
type vector2 = array[1..10000] of integer;
var y:vector2;
fin,fout:textfile;
i,e,a,lsirm,lsirn:integer;
function max(num1,num2:integer):integer;
begin
if num1>num2 then
    max:=num1
else
    max:=num2;
end;

begin
a:=0;
assign (fin, 'cmlsc.in');
reset(fin);
assign (fout, 'cmlsc.out');
rewrite(fout);
read(fin, lsirm, lsirn);
for i:=1 to lsirm do
    read(fin,x[i+2,1]);
for i:=1 to lsirn do
    read(fin,x[1,i+2]);
for i:=3 to lsirm+2 do begin
    for e:=3 to lsirn+2 do begin
        if x[1,e]=x[i,1] then begin 
            x[i,e]:=x[i-1,e-1]+1;
            a:=a+1;
            y[a]:=x[1,e];
            end
        else
            x[i,e]:=max(x[i-1,e],x[i,e-1]);
        end;
    end;

for i:=1 to lsirm+2 do begin
    writeln;
    for e:=1 to lsirn+2 do begin
        write(x[i,e]);
        end;
    end;
writeln(fout,x[lsirm+2,lsirn+2]);
for i:=1 to a do 
    write(fout,y[i],' ');





close(fin);
close(fout);
end.
//1 7 3 9 8
//7 5 8