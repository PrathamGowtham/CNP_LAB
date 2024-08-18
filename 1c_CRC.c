#include <stdio.h>
#define DEGREE 16

void xor_division(int data[], int length, int remainder[]) {
    int ccit[DEGREE + 1] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    for (int i = 0; i < length; i++) remainder[i] = data[i];
    for (int i = 0; i <= length - DEGREE - 1; i++) {
        if (remainder[i] == 1) {
            for (int j = 0; j <= DEGREE; j++) {
                remainder[i + j] ^= ccit[j];
            }
        }
    }
}

int main() {
    int data[100], length = 0;
    char ch;
    
    // Input original data
    printf("Enter the Data to be transmitted: ");
    while ((ch = getchar()) != '\n') data[length++] = ch - '0';
    
    // Append zeros for CRC calculation
    for (int i = length; i < length + DEGREE; i++) data[i] = 0;

    // Calculate CRC and store the remainder
    int remainder[length + DEGREE];
    xor_division(data, length + DEGREE, remainder);

    // Transmit the data (original data + CRC)
    printf("Transmitting Data: ");
    for (int i = 0; i < length; i++) printf("%d", data[i]);
    for (int i = length; i < length + DEGREE; i++) {
        data[i] = remainder[i];  // Append CRC to data
        printf("%d", data[i]);
    }
    printf("\n");

    // Input received data
    printf("Enter the received data: ");
    int received_data[100], received_length = 0;
    while ((ch = getchar()) != '\n') received_data[received_length++] = ch - '0';

    // Calculate CRC for the received data to check for errors
    int received_remainder[received_length];
    xor_division(received_data, received_length, received_remainder);

    // Display the remainder after receiving
    printf("Remainder after receiving: ");
    for (int i = received_length - DEGREE; i < received_length; i++) {
        printf("%d", received_remainder[i]);
    }
    printf("\n");

    // Check if the remainder is zero (no errors)
    int error = 0;
    for (int i = 0; i < received_length; i++) {
        if (received_remainder[i] != 0) {
            error = 1;
            break;
        }
    }

    // Output the result
    if (!error) {
        printf("Actual Data: ");
        for (int i = 0; i < received_length - DEGREE; i++) {
            printf("%d", received_data[i]);
        }
    } else {
        printf("Received Data is Not correct");
    }

    return 0;
}
