#include <stdio.h>
#include <stdint.h> // to use uint32_t

int main(int argc, char* argv[]) {
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;

    int size = 0;

    uint8_t num1_buffer[4];
    uint32_t num1 = 0;
    uint8_t num2_buffer[4];
    uint32_t num2 = 0;

    if (argc != 3) {
        fputs("syntax : add-nbo <file1> <file2>", stderr);
    }

    // thousand.bin file open
    fp1 = fopen(argv[1], "rb");

    if (fp1 == NULL) {
        fputs("File Open Fail", stderr);
    }

    fseek(fp1, 0, SEEK_END);
    size = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    // thousand.bin file size check
    if (size < 4) {
        fputs("files must have 4 bytes", stderr);
    }

    fread(num1_buffer, sizeof(uint8_t), 4, fp1);
    fclose(fp1);

    // num1
    num1 = (num1_buffer[0] << 24) | (num1_buffer[1] << 16) | (num1_buffer[2] << 8) | (num1_buffer[3]);
    
    

    // five-hundred.bin file open
    fp2 = fopen(argv[2], "rb");

    if (fp2 == NULL) {
        fputs("File Open Fail", stderr);
    }

    fseek(fp2, 0, SEEK_END);
    size = ftell(fp2);
    fseek(fp2, 0, SEEK_SET);

    // five-hundred.bin file size check
    if (size < 4) {
        fputs("files must have 4 bytes", stderr);
    }

    fread(num2_buffer, sizeof(uint8_t), 4, fp2);
    fclose(fp2);

    // num2
    num2 = (num2_buffer[0] << 24) | (num2_buffer[1] << 16) | (num2_buffer[2] << 8) | (num2_buffer[3]);

    // print sum
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);

    return 0;
}