#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Incorrect Number of Arguments\n");
        printf("Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    char *ext = strrchr(output_file, '.');

    if (ext != NULL && strcmp(ext, ".wav") != 0)
    {
        printf("Output is not a WAV file\n");
        return 1;
    }
    // Open input file for reading
    FILE *input = fopen(input_file, "r");
    if (input == NULL)
    {
        printf("The file cannont be opened. The program will now exit.\n");
        return 1
    }

    // Read header
    WAVHEADER input_header;
    fread(&input_header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    int format = check_format(input_header);
    if (format == 1)
    {
        printf("Input is not a WAV file\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    BYTE check = {"W", "A", "V", "E"};

    for (int i  = 0; i < 4; i++)
    {
        if (header.format[i] != check[i])
        {
            return 1
        }
    }
    
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}