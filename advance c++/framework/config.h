#define VERSION_MAJOR @VERSION_MAJOR
#define VERSION_MINOR @VERSION_MINOR

#if defined WIN32 || defined WIN64
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
