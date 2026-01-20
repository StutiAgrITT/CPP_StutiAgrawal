#ifdef _WIN32
#define WINDOWS_OS
#elif __linux__
#define LINUX_OS
#elif __APPLE__
#define MAC_OS
#endif

int getOSCode();