#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** missingWords(char* s, char* t, int* result_size) {
    char** result = (char**)malloc(3 * sizeof(char*)); // 先给result动态分配内存

    char* str = NULL; // 中间缓存
    int i = 0; // s字符串的索引
    int j = 0; // t字符串的索引

    while (s[i] != '\0') {
        if (s[i] != t[j]) { // 不同单词时
            int m = 0;

            // 动态分配足够的空间来容纳当前不匹配的单词
            str = (char*)malloc(strlen(s) * sizeof(char));
            
            while (s[i] != ' ' && s[i] != '\0') {
                str[m] = s[i];
                m++;
                i++;
            }
            str[m] = '\0'; // 手动加一个字符串结束符

            result[*result_size] = str; // 将str的地址赋给result的下一个字符地址
            (*result_size)++;

            // 注意：这里应该释放 str 的内存
            // free(str);
        } else {
            while (t[j] != ' ' && s[i] == t[j] && t[j] != '\0') { // 遇到相同字符时
                j++;
                i++;
            }
            if (t[j] != '\0') {
                j++;
            }
        }
        if (s[i] != '\0') {
            i++;
        } else {
            break;
        }
    }

    return result;
}

int main() {
    int m = 0;
    char* a = "my name is cy";
    char* b = "my name is xmj";
    char ** c;
    int d = 0;
    c = missingWords(a, b, &d);
    while (m < d) {
        printf("%s", c[m]);

        // 注意：需要释放每个不匹配单词的内存
        free(c[m]);
        m++;
    }
    printf("\n");
    if (strcmp(a,b) == 0){
        printf("a is equal to b. \n");
    }
    else{
	    printf("a is not equal to b. \n");
    }
    // 注意：需要释放result数组的内存
    free(c);

    return 0;
}

