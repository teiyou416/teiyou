#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



char* missingLetters(char* s, char* t) {
    int s_length = strlen(s);
    int t_length = strlen(t);
    int result_size = 0;
    char* result = (char*)malloc((s_length + 1) * sizeof(char)); 

    int i = 0;
    
    while (s[i] != '\0' || t[j] != '\0') {
        if (s[i] != t[j]) {
            result[result_size++] = s[i];
        } else {
            i++;
        }
        j++;
    }
    result[result_size] = '\0'; 

    return result;
}

int main() {
    char* a = "abcdef";
    char* b = "abzyt";
    char* c = missingLetters(a, b);
    if(strcmp( a, b)==0){
    printf("a is equal to b");
    }else{
     printf("a is not equal to b\n");
    }
    printf("%s\n", c);
    free(c); 
    return 0;
}

