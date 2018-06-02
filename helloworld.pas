program test;
var
  x : Real;
  y : Integer;

procedure Proc(var x : Integer);
begin
  x := 0;
end;

function Fun(x : Real) : Real;
var
  y : Real;
begin
  y := 2 * x;
end;

begin
  x := 1.0;
  x := Fun(x);
  Proc(y);

end.
