// Import di tutte le librerie necessarie per far funzionare il programma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>

int main () {

   system("@cls||clear");         // Comando per pulire la Shell contemporaneamente all'esecuzione del programma
   char M[129];                   // Dichiarazione dell'Array di caratteri M
   char k[129];                   // Dichiarazione dell'Array di caratteri k
   char C[129];                   // Dichiarazione dell'Array di caratteri C
   int scelta=0;                  // Dichiarazione ed inizializzazione della variabile intera scelta
   int i=1;                       // Dichiarazione ed inizializzazione della variabile intera i
   time_t t;

   /*
   printf("\n--------------ENCRYPTION--------------\n");

   printf("\n  +++++        + + + + +           +        ");
   printf("    +     +      +                 +          ");
   printf("    +     +      +               +            ");
   printf("    +++++++      +             +              ");
   printf("    + +          +            +     +         ");
   printf("    +  +         +           + + + + + +      ");
   printf("    +   +        +                  +         ");
   printf("    +     +      + + + + +          +       \n");

   printf("\n--------------DECRYPTION--------------\n");

   */

   printf("\033[1;31m");           // Questo tipo di printf sevono per cambiare colore
   printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/ RC4 ENCRYPTION ALGORITHM \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n");
   printf("\033[1;33m");
   do {
   printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
   printf("Inserisci la stringa che andrà cifrata in XOR, massimo 128 caratteri.\nSe la Stringa dovesse superare i 128 caratteri i restanti andranno scartati: \n");
   printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
   printf("\n");
   printf("-> ");
   printf("\033[0m");

   fgets(M, 129, stdin);               // Dopo aver chiesto tramite i printf qua sopra di inserire una stringa di massimo 129 caratteri, in questa linea faccio digitare da tastiera e salvare in M
   }while (strlen(M) - 1 == 0);
   if (!strchr(M, '\n')) {
      while (fgetc(stdin)!= '\n');
   }

   size_t lun_m = strlen(M) - 1;       // Dichiaro la variabile intera lun_m e la inizializzo con il numero dei caratteri contenuti nell'Array M - 1

   do{

      printf("\033[1;33m");
      printf("\n(1) Vuoi inserire te la seconda stringa da tastiera per la cifratura\n");
      printf("(2) Vuoi far generare automaticamente la seconda stringa per la cifratura\n");
      printf("\n-> ");
      printf("\033[0m");
      scanf("%d", &scelta);            // Inserimento da tastiera della scelta
      printf("\033[1;31m");

      switch (scelta) {                //switch / case per controllare la scelta fatta dall'utente
         case 1: break;
         case 2: break;

         default: printf("\n-------------------------------------------------\n");
                  printf("HAI FATTO UNA SCELTA NON CONTEMPLATA, RIPROVA\n");
                  printf("-------------------------------------------------\n");
                  while(getchar()!='\n');                // Questo comando fa in modo che eventuali altri caratteri prima del 'new line' non interferiscano con eventuali successive chiamate a funzioni come scanf(), etc...
                  break;
      }

   }while (scelta!=1 && scelta!=2);

   printf("\033[1;33m");
   while(getchar()!='\n');
   if (scelta == 2) {                        // Ora sapendo che scelta contiene o 1 o 2 con questo if controllo se è due, se la condizione è vera verrà eseguito questo if
      srand((unsigned) time(&t));            // Funzione che serve a inizializzare la funzione per la generazione dei numeri casuali
      for (int i=0; i<=lun_m; i++) {         // Ciclo for che cicla finché i<=lun_m
         k[i]=(32 + rand() %96);             // In questa linea viene riempito l'Array k di numeri randomici (che in ASCII corrispondono a caratteri e simboli) posizione per posizione
      }

      printf("\033[1;35m");
      printf("\nStringa per cifrare");
      printf("\033[0m");
      printf(" :");
      printf("\033[1;35m");
      printf(" %s\n",k );                    // Stampa a video della stringa per cifrare (k)

      for (int i=0; i<=lun_m; i++) {         // Stesso ciclo for di sopra
         C[i] = M[i] ^ k[i];                 // In questa linea viene riempito l'Array C con il risultato dell'operazione XOR tra ogni elemento di M e di k, tutto finché la condizione del for non sarà falsa
      }
      printf("\033[1;32m");
      printf("\nStringa cifrata");
      printf("\033[0m");
      printf(" :");
      printf("\033[1;32m");
      printf(" %s\n",C );                    // Stampa a video della stringa cifrata (C)

      for (int i=0; i<=lun_m; i++) {         // Stesso ciclo for di sopra
         M[i] = C[i] ^ k[i];                 // In questa linea viene decifrata con lo XOR la stringa cifrata tramite la chiave di cifratura e la stringa cifrata restituendo la stringa in chiaro
      }
      printf("\033[0m");
      printf("\nStringa in chiaro : %s\n",M );     // Stampa a video la stringa in chiaro
   }
   else{
      while (i) {                            // Ciclo while infinito

         printf("\033[1;33m");
         printf("\nInserisci un'altra stringa di lunghezza maggiore o uguale a %ld.\n Se sarà più lunga di 128 i caratteri in più verranno scartati!\n", lun_m);
         printf("\n-> ");
         printf("\033[0m");
         fgets(k, 129, stdin);                            // Prendo una stringa da tastiera

         size_t lun_k = strlen(k)-1;                      // Dichiarazione e inizializzazione della variabile intera lun_k

         if (lun_k >= lun_m && lun_k < 129) {             // if che viene eseguito se l'utente ha inserito una stringa consona alla richiesta fatta

            for (int i=0; i<=lun_m; i++) {                // for come tutti gli altri
               C[i] = M[i] ^ k[i];                        // In questa linea viene riempito l'Array C con il risultato dell'operazione XOR tra ogni elemento di M e di k, tutto finché la condizione del for non sarà falsa
            }
            printf("\n");
            printf("\033[1;32m");
            printf("\nStringa cifrata");
            printf("\033[0m");
            printf(":");
            printf("\033[1;32m");
            printf("\n %s\n",C );                         // Stampa a video della stringa cifrata (C)

            for (int i=0; i<=lun_m; i++) {                // for come tutti gli altri
               M[i] = C[i] ^ k[i];                        // In questa linea viene decifrata con lo XOR la stringa cifrata tramite la chiave di cifratura e la stringa cifrata restituendo la stringa in chiaro
            }

            printf("\033[1;0m");
            printf("\nStringa in chiaro: %s\n",M );       // Stampa a video la stringa in chiaro
            break;                                        // Comando per uscire dal ciclo while infinito
         }
         else if (lun_k < lun_m) {                        // else if per verificare un'altra condizione
            printf("\033[1;31m");
            printf("\n----------------------------------------------------------------------------");
            printf("\nHAI INSERITO UNA STRINGA PIU' CORTA DEL LIMITE MINIMO DI %ld CARATTERI",lun_m);
            printf("\n----------------------------------------------------------------------------\n");
         }
      }
   }
return 0;
}
