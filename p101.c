#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isDelimiter(char c) {
    return c == ' ' || c == '\0';
}

char* missingLetters(char* s, char* t) {
    int s_length = strlen(s);
    int t_length = strlen(t);
    int result_size = 0;
    char* result = (char*)malloc((s_length + 1) * sizeof(char)); 
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] != t[j]) {
            result[result_size++] = s[i];
        } else {
            int temp_i = i;
            int temp_j = j;
            while (!isDelimiter(s[temp_i]) && s[temp_i] == t[temp_j] && t[temp_j] != '\0') {
                temp_i++;
                temp_j++;
            }
            if (isDelimiter(t[temp_j])) {
                i = temp_i - 1;
            } else {
                result[result_size++] = s[i];
            }
        }
        i++;
    }
    result[result_size] = '\0'; 

    return result;
}

int main() {
    char* a = "i am a stu";
    char* b = "i st";
    char* c = missingLetters(a, b);
    printf("%s\n", c);

    free(c); 
    return 0;
}

