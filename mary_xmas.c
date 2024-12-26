#include <stdio.h>
#include <string.h>

void printing_tree(const char *message, int levels) {
    printf("%s\n", message); 
    for (int i = 0; i < levels; i++) {
        int stars = i * 2 + 1; 
        int spaces = (30 - stars) / 2; 
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < stars; j++) {
            printf("x");
        }
        printf("\n");
    }
    
    for (int i = 0; i < 2; i++) {
        int spaces = (30 - 3) / 2; 
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("|||\n");
    }
}

int main(){
    const char *chat= "Merry Xmasss!";
    int levels = 10;

    printing_tree(chat, levels);  
    return 0;
 }