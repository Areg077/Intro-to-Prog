#include <stdio.h>
#include <string.h>

void main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    char compressed[100];
    char *src = str, *dest = compressed;
    
    while (*src) {
        char current = *src;
        int count = 0;
        while (*src == current) {
            count++;
            src++;
        }
        *dest++ = current;
        *dest++ = count + '0';
    }
    *dest = '\0'; 
    
    strcpy(str, compressed);
    printf("Compressed string: %s\n", str);
}
