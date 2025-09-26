#pragma once

typedef struct Auto Auto;
typedef struct AutoElettrica AutoElettrica;

void acceleraAuto(Auto *a);
void acceleraElettrica(Auto *a);
void ricaricaBatteria(AutoElettrica *a);