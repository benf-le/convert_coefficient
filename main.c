#include<stdio.h>
#include<math.h>
#include <conio.h>



// user-defined function to implement the conversion algorithm

typedef struct string string;

//Binary
long binToDec(long binaryNumber) {
    // declaration of variables
    long decimalRep = 0, temp, remainder, base = 1;
    temp = binaryNumber;

    // applying the conversion algorithm
    while (temp > 0) {
        // dividing the binary number and storing the rightmost digit in the remainder variable
        remainder = temp % 10;
        decimalRep = decimalRep + (remainder * base);
        temp /= 10;
        base *= 2;
    }
    return decimalRep;
}

long binToOct(long binaryNumber) {
    long temp = binaryNumber;
    long oct = 0, dec = 0, i = 0;

    // converting binary to decimal
    while (temp != 0) {
        dec += (temp % 10) * pow(2, i);
        ++i;
        temp /= 10;
    }
    i = 1;

    // converting to decimal to octal
    while (dec != 0) {
        oct += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }
    return oct;
}

long binToHex(long binaryNumber) {
    long hexadecimalnum = 0, i = 1, rem;


    while (binaryNumber != 0) {
        rem = binaryNumber % 10;
        hexadecimalnum = hexadecimalnum + rem * i;
        i = i * 2;
        binaryNumber = binaryNumber / 10;
    }

    return hexadecimalnum;

}

//Decimal

long decToOct(int decimalNumber) {
    long octalNumber = 0, i = 1;
    int remainder, temp;
    temp = decimalNumber;
    while (temp != 0) {
        remainder = temp % 8;
        temp = temp / 8;
        octalNumber = octalNumber + (remainder * i);
        i = i * 10;
    }
    return octalNumber;
}

long decToBin(long decimalNumber) {


    long binary = 0, remainder, product = 1;
    // Since the data type is int, it can only accept values up to 1023 before switching to long.

    while (decimalNumber != 0) {
        remainder = decimalNumber % 2;
        binary = binary + (remainder * product);
        decimalNumber = decimalNumber / 2;
        product *= 10;
    }
    return binary;

}
void decToHex(long decimalNumber) {
    if (decimalNumber < 16)
    {
        printf("%c","0123456789ABCDEF"[decimalNumber]); // hien thi ky tu thu n trong chuoi
        return;
    }
    else decToHex(decimalNumber / 16);
    printf("%c","0123456789ABCDEF"[decimalNumber % 16]);
}


int main() {
    printf("Enter the coefficient to convert: ");
    char coe;
    scanf("%c", &coe);
    long binaryNumber, decimalNumber, octNumber, hexNumber;

    switch (coe) {
        case 'B' :
            printf("Enter a binary number:  ");
            scanf("%ld", &binaryNumber);
            // calling the binaryToDecimal function and
            // storing the return value in decimalNumber variable
            decimalNumber = binToDec(binaryNumber);
            octNumber = binToOct(binaryNumber);
            hexNumber = binToHex(binaryNumber);

            printf("\nBinary number: %ld\nDecimal Number: %ld", binaryNumber, decimalNumber);
            printf("\nOctal Number: %ld", octNumber);
            printf("\nHexa Number: %lX", hexNumber);
            break;


        case 'D' :
            printf("Enter a decimal number:  ");
            scanf("%ld", &decimalNumber);
            octNumber = decToOct(decimalNumber);
            binaryNumber = decToBin(decimalNumber);

            printf("\nDecimal number: %ld\nBinary Number: %ld", decimalNumber, binaryNumber);

            printf("\nOctal Number: %ld", octNumber);
            printf("\nHex Number: "); decToHex(decimalNumber);
            break;


        case 'O':
            break;
    }


}
