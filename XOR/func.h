#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_BIN 9 //incluso il terminatore '\0'

char *char_to_bin(char c);
char *stringToBinary(char *s);
char bin_to_char(char *v);
void cifra(char *parola_da_cifarare, char chiave, char *file);
void decifra(char *file_da_decifrare, char chiave, char *file_output);
