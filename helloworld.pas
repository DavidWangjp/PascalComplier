program p;
var
  x : Real;
  y : Integer;
  z : Integer;

procedure Proc(var x : Integer);
begin
  x := 0;
end;

function Fun(x : Real; var z : Integer) : Real;
var
  t : Real;
begin
  t := 2 * x;
end;

begin
  x := 1.0;
  x := Fun(x, z);
  Proc(y);

end.
