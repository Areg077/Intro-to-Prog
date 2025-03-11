#include <stdio.h> 

int main() {
	FILE *The File = fopen("Ex_1.c", "r"); 
	if(The File == NULL) { 
		printf("No such a file!");
		return 0;
	}
	char brackets; 
	int row = 1; 
	int column = 0; 
	while((brackets = fgetc(The File)) != EOF) { 
		column++;
		if(brackets == '\n') {  
			row++;
			column = 0;
		}
		if(brackets == '{' || brackets == '}')
			printf("%c is in Row: %d, column: %d\n", brackets, row, column);
		}
	fclose(The File);
	return 0;
}

