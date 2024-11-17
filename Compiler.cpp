#include "Compiler.h"

void ReadUserCommands(const char* fname)
{

    assert(fname != NULL);

    FILE* UserCommands = fopen(fname, "r");

    fseek(UserCommands, 0, SEEK_END);
    size_t UserSize = (size_t)ftell(UserCommands);
    rewind(UserCommands);

    char* UserCommand = (char*)calloc(UserSize, sizeof(char));

    FILE* CPUCommands = fopen("CPUCommands.txt", "w");

    stackElem num = 0;

    while (fgets(UserCommand, (int)UserSize, UserCommands) != NULL)
    {
        if (sscanf(UserCommand, "push %lg\n", &num) == 1)
        {
            fprintf(CPUCommands, "1 %lg\n", num);
        }

        if (strcmp(UserCommand, "mul\n") == 0)
        {
            fprintf(CPUCommands, "2\n");
        }

        if (strcmp(UserCommand, "div\n") == 0)
        {
            fprintf(CPUCommands, "3\n");
        }

        if (strcmp(UserCommand, "sub\n") == 0)
        {
            fprintf(CPUCommands, "4\n");
        }

        if (strcmp(UserCommand, "out\n") == 0)
        {
            fprintf(CPUCommands, "0\n");
        }

        if (strcmp(UserCommand, "hlt\n") == 0)
        {
            fprintf(CPUCommands, "-1\n");
        }

        if (strcmp(UserCommand, "sum\n") == 0)
        {
            fprintf(CPUCommands, "5\n");
        }
    }

    fclose(UserCommands);
    fclose(CPUCommands);
    free(UserCommand);
}
