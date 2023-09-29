#include <stdio.h>
#include "./lib_logging/logging.h"

int main()
{
    setTerminalColor(DARK_BLUE);
    printf("Hello, world!\n");
    setTerminalColor(RESET);
    printf("after...\n");

    return 0;
}