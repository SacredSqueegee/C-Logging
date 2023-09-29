#include <stdio.h>
#include "./lib_logging/logging.h"

int main()
{
    printf("Hello, world!\n");
    Log_MSG(LOG_INFO, "%s", "This is a test message...");
    Log_Nest(LOG_ERROR, 0, "I'm a nested %s", "log message...");
    return 0;
}