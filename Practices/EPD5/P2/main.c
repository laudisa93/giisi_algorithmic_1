#include <stdio.h>
#include <stdlib.h>

int main()
{
    PROCEDURE AsignacionOptima(VAR b:COSTES; VAR x:ASIGNACION);
    VAR trabajador,tarea:CARDINAL;
    BEGIN
    FOR trabajador:=1 TO n DO (* inicializamos la matriz solucion *)
    FOR tarea:=1 TO n DOx[trabajador,tarea]:=FALSEENDEND;
    FOR trabajador:=1 TO n DO
    x[trabajador,MejorTarea(b,x,trabajador)]:=TRUE
    END
    END
    AsignacionOptima;
}
