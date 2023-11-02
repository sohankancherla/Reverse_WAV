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
        printf("The input file cannont be opened. The program will now exit.\n");
        return 1;
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
    FILE *output = fopen(output_file, "w");
    if (output == NULL)
    {
        printf("The output file cannont be opened. The program will now exit.\n");
        return 1;
    }
    // Write header to file
    fwrite(&input_header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(input_header);

    // Write reversed audio to file
    BYTE buffer[block_size];

    fseek(input, 0, SEEK_END);

    long audio_size = ftell(input) - sizeof(WAVHEADER);
    int audio_block = (int) audio_size / block_size;

    for (int i = audio_block - 1; i >= 0; i--)
    {
        fseek(input, sizeof(WAVHEADER) + i * block_size, SEEK_SET);
        fread(buffer, block_size, 1, input);
        fwrite(buffer, block_size, 1, output);
    }

    fclose(input);
    fclose(output);

}

int check_format(WAVHEADER header)
{
    BYTE check[] = {'W', 'A', 'V', 'E'};

    for (int i  = 0; i < 4; i++)
    {
        if (header.format[i] != check[i])
        {
            return 1;
        }
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    WORD bytePerSample = header.bitsPerSample / 8;
    return (header.numChannels * bytePerSample);
}