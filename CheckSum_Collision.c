#include <stdio.h>
#include <string.h>

// Weak checksum function (modulo 256)
unsigned char weak_checksum(const char *input) {
    unsigned char sum = 0;
    while (*input) {
        sum += *input; // Simple sum of ASCII values
        input++;
    }
    return sum % 256;  // Small output range to cause collisions
}

// Find two different strings with the same checksum
void find_collision() {
    char str1[] = "hello";
    char str2[] = "ifhmp";  // Slightly modified to force collision

    unsigned char checksum1 = weak_checksum(str1);
    unsigned char checksum2 = weak_checksum(str2);

    printf("String 1: \"%s\", Checksum: %u\n", str1, checksum1);
    printf("String 2: \"%s\", Checksum: %u\n", str2, checksum2);

    if (checksum1 == checksum2) {
        printf("Collision found! \"%s\" and \"%s\" have the same checksum.\n", str1, str2);
    } else {
        printf("No collision found. Try different strings.\n");
    }
}

int main() {
    find_collision();
    return 0;
}
