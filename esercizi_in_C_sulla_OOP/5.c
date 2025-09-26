/*
================================================================================
ESERCIZIO 5 – Astrazione in C
================================================================================

Spiegazione:
- L’astrazione consiste nel mostrare solo ciò che serve all’utente e nascondere
  i dettagli di implementazione.
- In C++ lo facciamo con classi astratte e metodi virtuali puri.
- In C possiamo ottenere qualcosa di simile separando l’interfaccia (.h)
  dall’implementazione (.c) e usando puntatori a funzione come "contratto".

Requisiti:
1. Definisci una struct "Forma" con un solo campo:
   - void (*disegna)(struct Forma*);

2. Non implementare direttamente Forma, ma fornisci due "implementazioni":
   - Cerchio (con raggio).
   - Rettangolo (con base, altezza).

3. Le funzioni di disegno devono rispettare l’interfaccia:
   - void disegnaCerchio(Forma* f);
   - void disegnaRettangolo(Forma* f);

4. Nel main():
   - Crea un array di `Forma*` con dentro un Cerchio e un Rettangolo.
   - Chiama `disegna` per ciascun elemento, senza sapere il tipo concreto.

--------------------------------------------------------------------------------
Domande concettuali:
1. In cosa l’astrazione è diversa dall’incapsulamento?
2. Perché in C++ usiamo classi astratte e metodi virtuali puri per l’astrazione?
3. Come possiamo simulare l’astrazione in C senza avere parole chiave dedicate?
================================================================================
*/


//qui va bene lo stesso codice dell'esercizio 4.c e 4.h
/*
La differenza è concettuale, non nel codice:
    Polimorfismo: ci interessa il comportamento diverso a runtime.
    Astrazione: ci interessa nascondere i dettagli e mostrare solo l’interfaccia (Forma con disegna).
*/