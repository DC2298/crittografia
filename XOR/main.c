#include "func.h"

int main(int argc, char **argv){

  if(argc != 5){
    if(argc == 2){
      char s[2];
      strcpy(s, argv[1]);
      if(argc == 2 && strcmp(s, "-h") == 0){
        printf("la sintassi corretta per richiamare il programma è la seguente:\n"
          "./nome_eseguibile -opzione parola_da_cifrare chiave nome_file.txt\n"
          "Ps nel file.txt verra scritta la parola cifrata\n"
          "-opzione puo o essere -c (per cifrare) o -d (per decifrare)");
        exit(-1);
      }
    }
    else{
      printf("ERRORE!\n richiama il comando -h per la vedere la sintassi corretta\nESEMPIO: ./xor -h\n");
      exit(-1);
    }
  }

  char s[2];
  strcpy(s, argv[1]);

  if(!strcmp(s, "-c")){
    char *parola_da_cifrare, chiave, *nome_file;
    int DIM_parola_da_cifrare, DIM_nome_file;
    parola_da_cifrare = (char*) malloc(sizeof(char)*strlen(argv[2]));
    nome_file = (char*) malloc(sizeof(char)*strlen(argv[4]));
    strcpy(parola_da_cifrare, argv[2]);
    chiave = argv[3][0];
    strcpy(nome_file, argv[4]);
    cifra(parola_da_cifrare, chiave, nome_file);
    free(parola_da_cifrare);
    free(nome_file);
  }

  if(strcmp(s, "-d") == 0){
    char *parola_da_decifrare, chiave, *nome_file;
    int DIM_parola_da_decifrare, DIM_nome_file;
    parola_da_decifrare = (char*) malloc(sizeof(char)*strlen(argv[2]));
    nome_file = (char*) malloc(sizeof(char)*strlen(argv[4]));
    strcpy(parola_da_decifrare, argv[2]);
    chiave = argv[3][0];
    strcpy(nome_file, argv[4]);
    decifra(parola_da_decifrare, chiave, nome_file);
    free(parola_da_decifrare);
    free(nome_file);
  }



  return 0;
}
