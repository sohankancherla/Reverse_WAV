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

    char *ext = strrchr(input_file, '.');
    char *ext2 = strrchr(output_file, '.');

    if (ext != NULL && strcmp(ext, ".wav") != 0)
    {
        printf("Input File is not a WAV file");
        return 1;
    }
    if (ext2 != NULL && strcmp(ext2, ".wav") != 0)
    {
        printf("Output File is not a WAV file");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    // Read header
    // TODO #3

    // Use check_format to ensure WAV format
    // TODO #4

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
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}