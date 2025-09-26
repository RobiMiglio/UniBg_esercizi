/*
================================================================================
DOMANDA 8 – Cicli annidati, operatori logici, break/continue
================================================================================

1. Scrivi un programma che stampi una tabella 5x5 di numeri interi da 1 a 25.

2. Regole:
   - Usa due `for` annidati.
   - Se il numero è divisibile sia per 2 che per 3, salta la stampa (usa `continue`).
   - Se il numero raggiunge 20, interrompi completamente l’esecuzione della tabella
     (usa `break`).

3. Output atteso (semplificato):
   - Una tabella con numeri da 1 a 25, ma senza quelli divisibili per 2 e 3,
     e interrotta non appena si arriva a 20.

--------------------------------------------------------------------------------
Domanda teorica:
- Qual è la differenza tra `break` e `continue` nei cicli annidati?
- Come funziona la valutazione corta (short-circuit) negli operatori logici `&&`
  e `||` in C?
================================================================================
*/

#include <stdio.h>

int main()
{
    int arrayMultidimensione[5][5];

    int temp = 0;
    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            temp++;
            if(temp == 20)
            {
                break;
            }
            if((temp%2 == 0) && (temp%3 == 0))
            {
                continue;
            }
            arrayMultidimensione[i][k] = temp; 
            printf("%d ",arrayMultidimensione[i][k]); 
        }
        if(temp == 20)
        {
            break;
        }
        printf("\n");
    }
    return 0;
}


/*
- `break` → interrompe immediatamente l’intero ciclo in cui si trova (esce dal ciclo).
- `continue` → interrompe solo l’iterazione corrente e passa subito alla successiva,
  senza eseguire le istruzioni rimanenti nel ciclo.

- **Short-circuit negli operatori logici:**
  - `&&` → se la prima condizione è falsa, la seconda NON viene valutata.
  - `||` → se la prima condizione è vera, la seconda NON viene valutata.

⚠️ Questo meccanismo è utile per evitare errori o calcoli inutili.
Esempio:
   if (ptr != NULL && ptr->campo == 5) { ... }
   --> La seconda parte viene valutata solo se ptr non è NULL.

================================================================================
*/
