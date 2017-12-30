#include "func.h"

char *char_to_bin(char c){
  int i, j=0;
  char *x;
  x = (char*) malloc(sizeof(char)*DIM_BIN);

  for(i = 7; i >= 0; --i){
    x[j] = ((c & (1 << i)) ? '1' : '0');
    j++;
  }

  return x;
}

char* stringToBinary(char* s) {
  if(s == NULL) return 0;
  size_t len = strlen(s);
  char *binary = malloc(len*8 + 1);

  for(size_t i = 0; i < len; ++i) {
    char ch = s[i];
    for(int j = 7; j >= 0; --j){
      if(ch & (1 << j)) strcat(binary,"1");
      else strcat(binary,"0");          }
    }

  return binary;
}

char bin_to_char(char *v){
  char carattere = strtol(v, 0, 2);
  return carattere;
}


void cifra(char *parola_da_cifrare, char chiave, char *file){
  FILE *f;
  int i, j=0;
  char *word, *key;

  if((f=fopen(file, "w")) == NULL){
    printf("ERRORE!\ncreazione file non riuscita!!");
    exit(-1);
  }

  key = char_to_bin(chiave);
  word = stringToBinary(parola_da_cifrare);

  for(i=0; word[i] != '\0'; i++){
    if(key[j] == '\0') j=0;
    fprintf(f, "%d", (int)(word[i] ^ key[j]));
  }

  if(fclose(f)){
    printf("Errore nella chiusura del file\n");
    exit(-2);
  }

  free(key);
  free(word);
}

void decifra(char *file_da_decifrare, char chiave, char *file_output){
  FILE *f, *fp, *ptr;
  int i, j=0, len = 0;
  char *word = NULL, *key = (char*) malloc(sizeof(char)*DIM_BIN), *parola = NULL, temp[DIM_BIN];

  if((f=fopen(file_da_decifrare, "r")) == NULL){
    printf("ERRORE!\nApertura file non riuscita!!");
    exit(-1);
  }
  if((fp=fopen("try.txt", "w")) == NULL){
    printf("ERRORE!\nApertura file non riuscita!!");
    exit(-1);
  }
  if((ptr=fopen(file_output, "w")) == NULL){
    printf("ERRORE!\nApertura file non riuscita!!");
    exit(-1);
  }

  key = char_to_bin(chiave);

  fseek(f, 0L, SEEK_END);
  long c = ftell(f);
  fseek(f, 0L, SEEK_SET);

  parola = (char*) realloc(parola, sizeof(char)*c);
  word = (char*) realloc(parola, sizeof(char)*c);
  fscanf(f ,"%s", parola);

  for(i=0; parola[i] != '\0'; i++){
    if(key[j] == '\0') j=0;
    fprintf(fp, "%d", (int)(parola[i] ^ key[j]));
  }
  fscanf(fp, "%s", word);

  j=0;
  for(i=0; i < strlen(word); i++){
    memcpy(temp, word+j, 8);
    fprintf(ptr,"%c", bin_to_char(temp));
    j += 8;
  }
  printf("decryption ended with success\nCreate file output %s\n", file_output);
  if(fclose(f)){
    printf("Errore nella chiusura del file\n");
    exit(-2);
  }
  if(fclose(fp)){
    printf("Errore nella chiusura del file\n");
    exit(-2);
  }
  if(fclose(ptr)){
    printf("Errore nella chiusura del file\n");
    exit(-2);
  }

  free(key);
  free(word);
  free(parola);
}
