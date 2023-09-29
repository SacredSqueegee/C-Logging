# C-Logging
Lightweight terminal logger written in C

Easy and straightforward to use. Simply include the logging.h header and statically link the library

## Usage
There are currently only two functions to call:
1. `LogType_t Log_MSG(LogType_t logType, const char* msgFormat, ...);`
2. `LogType_t Log_Nest(LogType_t logType, uint8_t nestingLevel, const char* msgFormat, ...);`

These functions are just fancy wrappers around the printf() function, allowing for better viewing of logs in the terminal.

There is the concept of a regular and nested log message. The regular log message will simply display your formatted log on the screen and prepend a colored identifier to the message based on the LogType. Nested messages will prepend a different colored identifier to the front of your message and tab it over based on the tabbing level provided (must be 1 or greater, providing 0 is translated to 1).

These functions will always return the value of `logType` that is passed in, modulo by `sizeof(LogType_t)`. This simply means that the only viable range of return values (as this library currently stands) is 0 through 3. Even if you pass in 5 for the log type, 1 will be returned as `5 % 4 = 1`.

By default, a space will always be above any Log_MSG(). This is controlled by the `spaceAbove` boolean in the global `g_logState` structure. TODO: allow modification of this value in the future.

Defaults:
> ~ These can be changed in the global g_LogState struct in logging.c
> 
> - LOG_ERROR
>     + identifier:           [-]
>     + nested identifier:    \_
>     + color:                red
> - LOG_WARNING
>     + identifier:           [!]
>     + nested identifier:    \_
>     + color:                yellow
> - LOG_INFO
>     + identifier:           [+]
>     + nested identifier:    \_
>     + color:                green
> - LOG_DEBUG
>     + identifier:           [debug]
>     + nested identifier:    \_
>     + color:                cyan

## Examples
```c
#include <logging.h>

int main()
{
    Log_MSG(LOG_INFO, "%s", "This is a test message...");
    Log_Nest(LOG_ERROR, 0, "I'm a nested %s", "log message...");

    return 0;
}
```

To compile: `clang test.c -L/path/to/liblogging.a -llogging -o test.out`

Terminal output:

![Screenshot 2023-09-29 at 2 06 13 PM](https://github.com/SacredSqueegee/C-Logging/assets/16947007/27043d15-d57e-4f0a-9dc1-84c38eb8a1b7)
