1.
#include <stdio.h>

int main() {
    double num1, num2;
    char op;
    
    printf("Enter an expression (e.g., 5 + 6): ");
    scanf("%lf %c %lf", &num1, &op, &num2);
    
    if (op == '+')
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
    else if (op == '-')
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
    else if (op == '*')
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
    else if (op == '/') {
        if (num2 != 0)
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
        else
            printf("Error: Division by zero is not allowed.\n");
    } else
        printf("Invalid operation\n");

    return 0;
}


1.1
#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    
    printf("Enter an expression (e.g., 10 / 3): ");
    scanf("%lf %c %lf", &num1, &op, &num2);
    
    if (op == '+')
        result = num1 + num2;
    else if (op == '-')
        result = num1 - num2;
    else if (op == '*')
        result = num1 * num2;
    else if (op == '/') {
        if (num2 != 0)
            result = num1 / num2;
        else {
            printf("Error: Division by zero is not allowed.\n");
            return 1;
        }
    } else {
        printf("Invalid operation\n");
        return 1;
    }
    
    printf("%.2lf %c %.2lf = %.3lf\n", num1, op, num2, result);
    
    return 0;
}


1.2
#include <stdio.h>

int main() {
    double num1, num2;
    char op;
    
    printf("Enter an expression (e.g., 10 / 3): ");
    scanf("%lf %c %lf", &num1, &op, &num2);
    
    switch (op) {
        case '+': 
            printf("%.2lf + %.2lf = %.3lf\n", num1, num2, num1 + num2); 
            break;
        case '-': 
            printf("%.2lf - %.2lf = %.3lf\n", num1, num2, num1 - num2); 
            break;
        case '*': 
            printf("%.2lf * %.2lf = %.3lf\n", num1, num2, num1 * num2); 
            break;
        case '/': 
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.3lf\n", num1, num2, num1 / num2);
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        default:
            printf("Invalid operation\n");
    }
    
    return 0;
}


2.
#include <stdio.h>

int main() {
    int grade;
    
    printf("Enter grade (0-100): ");
    scanf("%d", &grade);

    if (grade >= 90) 
        printf("Your grade is A\n");
    else if (grade >= 80) 
        printf("Your grade is B\n");
    else if (grade >= 70) 
        printf("Your grade is C\n");
    else if (grade >= 60) 
        printf("Your grade is D\n");
    else 
        printf("Your grade is F\n");

    return 0;
}


2.1
#include <stdio.h>

int main() {
    int grade;
    
    while (1) {
        printf("Enter grade (0-100) or -1 to exit: ");
        scanf("%d", &grade);

        if (grade == -1) 
            break;

        if (grade >= 90) 
            printf("Your grade is A\n");
        else if (grade >= 80) 
            printf("Your grade is B\n");
        else if (grade >= 70) 
            printf("Your grade is C\n");
        else if (grade >= 60) 
            printf("Your grade is D\n");
        else 
            printf("Your grade is F\n");
    }

    return 0;
}


3.
#include <stdio.h>

int main() {
    int N, sum = 0;
    
    printf("Enter a number (1-1000): ");
    scanf("%d", &N);
    
    for (int i = 1; i < N; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    
    printf("Sum of multiples of 3 and 5 below %d: %d\n", N, sum);
    return 0;
}


4.
#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    
    printf("Sum of digits: %d\n", sum);
    return 0;
}


5.
#include <stdio.h>

int main() {
    int num, reversed = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    printf("Reversed number: %d\n", reversed);
    return 0;
}


6.
#include <stdio.h>

int main() {
    int num, isPrime = 1;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num <= 1) 
        isPrime = 0;
    else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    
    if (isPrime)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    return 0;
}


6.1
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    
    printf("Enter N: ");
    scanf("%d", &N);
    
    printf("Prime numbers up to %d: ", N);
    for (int i = 2; i <= N; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    
    printf("\n");
    return 0;
}


7.
#include <stdio.h>

int main() {
    int num, original, reversed = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    if (original == reversed)
        printf("The number is a palindrome\n");
    else
        printf("The number is not a palindrome\n");

    return 0;
}


8.
#include <stdio.h>

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Concatenated number: %d%d\n", num1, num2);
    
    return 0;
}


9.
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num > 0 && (num & (num - 1)) == 0)
        printf("%d is a power of 2\n", num);
    else
        printf("%d is not a power of 2\n", num);
    
    return 0;
}


10.
#include <stdio.h>

int main() {
    int N, M;
    
    printf("Enter dimensions (N M): ");
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}


10.1
#include <stdio.h>

int main() {
    int N, M;
    char ch;
    
    printf("Enter dimensions (N M) and a character: ");
    scanf("%d %d %c", &N, &M, &ch);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}


11.
#include <stdio.h>

int main() {
    int N;
    
    printf("Enter height: ");
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }

    printf("\n");
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}


12.
#include <stdio.h>

int main() {
    int N;
    
    printf("Enter base width: ");
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i += 2) {
        for (int j = 0; j < (N - i) / 2; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}


13.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    
    srand(time(0));
    number = rand() % 100 + 1;
    
    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");
        else
            printf("Correct! You guessed in %d attempts.\n", attempts);
    } while (guess != number);

    return 0;
}


14.
#include <stdio.h>

int main() {
    int low = 1, high = 100, guess, response;
    
    printf("Think of a number between 1 and 100.\n");
    
    while (low <= high) {
        guess = (low + high) / 2;
        printf("Is it %d? (1: Too low, 2: Too high, 3: Correct): ", guess);
        scanf("%d", &response);
        
        if (response == 1)
            low = guess + 1;
        else if (response == 2)
            high = guess - 1;
        else {
            printf("I guessed your number!\n");
            break;
        }
    }
    
    return 0;
}


15.
#include <stdio.h>

int main() {
    int numbers[10], min, max;
    
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &numbers[i]);
    
    min = max = numbers[0];

    for (int i = 1; i < 10; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
    }

    printf("Minimum: %d, Maximum: %d\n", min, max);
    return 0;
}


16.
#include <stdio.h>

int main() {
    int count[10] = {0}, num;
    
    printf("Enter numbers (1-10), enter -1 to stop: ");
    
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        if (num >= 1 && num <= 10) count[num - 1]++;
    }

    for (int i = 0; i < 10; i++)
        printf("%d appears %d times\n", i + 1, count[i]);

    return 0;
}


17.
#include <stdio.h>

void toBinary(int num) {
    for (int i = 3; i >= 0; i--)
        printf("%d", (num >> i) & 1);
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    toBinary(num);
    printf("\n");
    
    return 0;
}


18.
#include <stdio.h>
#include <math.h>

int main() {
    char binary[9];
    int decimal = 0;
    
    printf("Enter a binary number: ");
    scanf("%s", binary);
    
    for (int i = 0; binary[i] != '\0'; i++)
        decimal = decimal * 2 + (binary[i] - '0');
    
    printf("Decimal: %d\n", decimal);
    return 0;
}


19.
#include <stdio.h>

int main() {
    int arr[10], N, found = 0;
    
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to remove: ");
    scanf("%d", &N);

    for (int i = 0; i < 10; i++) {
        if (arr[i] == N && !found) {
            found = 1;
        } else {
            printf("%d ", arr[i]);
        }
    }

    if (!found) printf("Number not found.");
    
    return 0;
}


20.
#include <stdio.h>

int main() {
    int N;
    
    printf("Enter array size: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = N - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    return 0;
}


21.
#include <stdio.h>

int main() {
    int N, sum = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    
    int arr[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);
    return 0;
}


22.
#include <stdio.h>

int main() {
    int N, sorted = 1;
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    
    int arr[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted)
        printf("Yes, sorted.\n");
    else
        printf("No, not sorted.\n");

    return 0;
}


23.
#include <stdio.h>

void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int N;
    
    printf("Enter number of elements: ");
    scanf("%d", &N);
    
    int arr[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, N);

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}


24.
#include <stdio.h>

int main() {
    int N, M;
    
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to delete (1-%d): ", N);
    scanf("%d", &M);

    if (M < 1 || M > N) {
        printf("Invalid position!\n");
        return 1;
    }

    for (int i = M - 1; i < N - 1; i++)
        arr[i] = arr[i + 1];

    for (int i = 0; i < N - 1; i++)
        printf("%d ", arr[i]);

    return 0;
}


25.
#include <stdio.h>

int main() {
    int N, K, M;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    int arr[N + 1];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to insert: ");
    scanf("%d", &K);
    
    printf("Enter position (1-%d): ", N + 1);
    scanf("%d", &M);

    if (M < 1 || M > N + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    for (int i = N; i >= M; i--)
        arr[i] = arr[i - 1];

    arr[M - 1] = K;

    for (int i = 0; i <= N; i++)
        printf("%d ", arr[i]);

    return 0;
}


26.
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);

    printf("Uppercase: %s\n", str);
    
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);

    printf("Lowercase: %s\n", str);

    return 0;
}


27.
#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first word: ");
    scanf("%s", str1);
    
    printf("Enter second word: ");
    scanf("%s", str2);

    if (strlen(str1) != strlen(str2)) {
        printf("Not anagrams\n");
        return 0;
    }

    sortString(str1);
    sortString(str2);

    if (strcmp(str1, str2) == 0)
        printf("They are anagrams\n");
    else
        printf("Not anagrams\n");

    return 0;
}



28.
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (strstr(str1, str2) != NULL)
        printf("'%s' is a substring of '%s'\n", str2, str1);
    else
        printf("'%s' is not a substring of '%s'\n", str2, str1);

    return 0;
}

