program p;
var
  i : Integer;
function F(x : Integer) : Integer;
begin
  F := 2 * x;
end;

begin
  i := 1;
  i := F(i);
end.
