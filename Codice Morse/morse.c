//REQUIERE sox

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#define DIM 10000

const static char *table[52][2]= {{"a","._"}, {"b","_..."}, {"c","_._."}, {"d","_.."}, {"e","."},\
                    {"f",".._."}, {"g","__."}, {"h","...."}, {"i",".."}, {"j",".___"},\
                    {"k","_._"}, {"l","._.."}, {"m","__"}, {"n", "_."}, {"o","___"},\
                    {"p",".__."}, {"q","__._"}, {"r","._."}, {"s","..."}, {"t","_"},\
                    {"u",".._"}, {"v","..._"}, {"w",".__"}, {"x", "_.._"}, {"y","_.__"},\
                    {"z","__.."}, {"1",".____"}, {"2","..___"}, {"3","...__"}, {"4","...._"},\
                    {"5","....."}, {"6","_...."}, {"7","__..."}, {"8","___.."}, {"9","____."},\
                    {"0","_____"}, {".","._._._"}, {",","__..__"}, {"+","._._."}, {"=","_..._"},\
                    {"?","..__.."}, {"(","_.__."}, {")","_.__._"}, {"-","_...._"}, {"""","._.._."},\
                    {"_","..__._"}, {"'",".____."}, {":","___..."}, {";","_._._."}, {"@",".__._."}, {"/","_.._."},{" ", "/"}};

int main(void){
  char frase[DIM], x[DIM] = {'\0'};
  int i = 0, j, k = 0;

  puts("Inserisci stringa da trasformare in codice morse: ");
  fgets(frase, DIM-1 , stdin);
  while(i<strlen(frase)){
    tolower(frase[i]);
    for(j=0; j<52; j++){
      if(frase[i] == **table[j]){
        strcat(x, table[j][1]);
        break;
      } 
    }
    i++;
  }
  while(k<strlen(x)){
      
      if(x[k] == '.'){
        system("echo . && echo UklGRn4AAABXQVZFZm10IBAAAAABAAEARKwAAIhYAQACABAAZGF0YVoAAAAAABkJBBKPGpQi4SlZMNQ1ODptPWY"
          "/FUB0P5I9ZDoXNqIwPSrzIvsacxKOCXMAXfdq7t3lzt141vTPa8r7xbLCrcDtv3rAUsJnxa/JD89w1afcn+QZ7QL2Fv8="
          "| base64 -d | play -q -t wav - repeat 250"); 
        sleep(0.5);
      }

      if(x[k] == '_'){
        system("echo _ && echo UklGRn4AAABXQVZFZm10IBAAAAABAAEARKwAAIhYAQACABAAZGF0YVoAAAAAABkJBBKPGpQi4SlZMNQ1ODptPWY"
          "/FUB0P5I9ZDoXNqIwPSrzIvsacxKOCXMAXfdq7t3lzt141vTPa8r7xbLCrcDtv3rAUsJnxa/JD89w1afcn+QZ7QL2Fv8=" 
          "| base64 -d | play -q -t wav - repeat 700");
        sleep(0.5);
      }

      if(x[k] == '/'){
        system("echo /");
        sleep(1);
      }
      k++;
    }

  puts("");
  return 0;
}
