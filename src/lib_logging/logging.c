#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "logging.h"

// Define terminal colors for escape sequences
typedef enum
{
    RESET = 0,
    BLACK = 30,
    DARK_RED = 31,
    DARK_GREEN = 32,
    DARK_YELLOW = 33,
    DARK_BLUE = 34,
    DARK_MAGENTA = 35,
    DARK_CYAN = 36,
    GRAY = 37,
    DARK_GRAY = 90,
    RED = 91,
    GREEN = 92,
    YELLOW = 93,
    BLUE = 94,
    MAGENTA = 95,
    CYAN = 96,
    WHITE = 97
} ColorCodes_t;


typedef struct
{
    const char* identifier;
    const char* nestedIdentifier;
    ColorCodes_t colorCode;
} LogIdentifier_t;


typedef struct
{
    LogType_t logLevel;
    bool spaceAbove;

    LogIdentifier_t error;
    LogIdentifier_t warning;
    LogIdentifier_t info;
    LogIdentifier_t debug;
} LogState_t;


// Setup default Global Log State
LogState_t g_LogState = {
    .logLevel = LOG_DEBUG,
    .spaceAbove = true,
    .error = {
        .identifier = "[-]",
        .nestedIdentifier = "\\_",
        .colorCode = RED
    },
    .warning = {
        .identifier = "[!]",
        .nestedIdentifier = "\\_",
        .colorCode = YELLOW
    },
    .info = {
        .identifier = "[+]",
        .nestedIdentifier = "\\_",
        .colorCode = GREEN
    },
    .debug = {
        .identifier = "[debug]",
        .nestedIdentifier = "\\_",
        .colorCode = CYAN
    },
    
    
};



// Helper functions
// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

static void setTerminalColor(ColorCodes_t colorCode)
{
    printf("%s%i%s", "\033[0;", colorCode, "m");
}

static LogType_t ValidateLogType(LogType_t LogType)
{
    return LogType % sizeof(LogType_t);
}


// Public API Functions
// =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

int Log_MSG(LogType_t logType, const char* msgFormat, ...)
{
    if (g_LogState.spaceAbove)
        printf("\n");

    // Prevent reading invalid memory when bad log type is passed in
    logType = ValidateLogType(logType);
    
    // Prepend logType identifier with color to msg
    LogIdentifier_t* p_logIdentifier = &g_LogState.error + logType;
    setTerminalColor(p_logIdentifier->colorCode);
    printf("%s ", p_logIdentifier->identifier);
    setTerminalColor(RESET);

    // Display msg
    va_list args;
    va_start(args, msgFormat);
    vprintf(msgFormat, args);
    va_end(args);
    printf("\n");

    return logType;
}


int Log_Nest(LogType_t logType, uint8_t nestingLevel, const char* msgFormat, ...)
{
    // Prevent reading invalid memory when bad log type is passed in
    logType = ValidateLogType(logType);

    // Apply nesting level and assure it's at least 1
    if (nestingLevel == 0)
        nestingLevel++;
    for (int i=0; i<nestingLevel; i++)
        printf("\t");
    
    // Prepend logType identifier with color to msg
    LogIdentifier_t* p_logIdentifier = &g_LogState.error + logType;
    setTerminalColor(p_logIdentifier->colorCode);
    printf("%s ", p_logIdentifier->nestedIdentifier);
    setTerminalColor(RESET);

    // Display msg
    va_list args;
    va_start(args, msgFormat);
    vprintf(msgFormat, args);
    va_end(args);
    printf("\n");
    
    return logType;
}



