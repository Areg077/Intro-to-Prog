#include <stdio.h> 
#include <string.h>
int main(){

	FILE *csv_file = fopen("csv_file.csv", "r");
	if(csv_file == NULL){ 
		printf("No such a file");
		return 0;
	}
	char line[64] = {0}; 
	int col; 
	int col_count = 0; 
	char search_value[32] = {0};
	char check_value[32] = {0}; 
	fgets(line, sizeof(line), csv_file); 
	printf("Enter the column and search value: ");
	scanf("%d %s", &col, search_value);  
	for(int i = 0; line[i] != '\0'; i++) { 
                if(line[i] == ',')
                      col_count++;
        }
	if(col_count + 1 < col || col <= 0){ 
                printf("invalid input\n");
                return 0;
        }

	printf("Column count: %d\n", col_count + 1);
       	while(fgets(line, sizeof(line), csv_file)){  
		col_count = 0; 
		for(int i = 0; line[i] != '\0'; i++){ 
			if(col_count + 1 == col){
				int k = i;
				int j = 0;
                                while(line[k] != ',' && line[k] != '\0' && line[k] != '\n'){ 
					check_value[j] = line[k];
					j++;
					k++;
				}
				break;
                        }
			if(line[i] == ',')  
                                col_count++;	
		}
		if(strcmp(check_value, search_value) == 0) 
			printf("%s\n",line);
		for(int i = 0; check_value[i] != '\0'; i++)
			check_value[i] = '\0';
	}
	fclose(csv_file);
	return 0;
}
