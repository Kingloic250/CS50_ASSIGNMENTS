#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to hexadecimal
void binaryToHex(char *binary) {
    int decimal = 0;
    int length = strlen(binary);
    
    // Convert binary to decimal
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal = decimal * 2 + 1;
        } else if (binary[i] == '0') {
            decimal = decimal * 2;
        } else {
            printf("Invalid binary number!\n");
            return;
        }
    }
    
    // Convert decimal to hexadecimal and print it
    printf("Hexadecimal: %X\n", decimal);
}

int main() {
    char binary[65]; // To hold up to 64-bit binary numbers
    
    // Input binary number
    printf("Enter a binary number: ");
    scanf("%64s", binary);
    
    // Convert and print hexadecimal
    binaryToHex(binary);
    
    return 0;
}
