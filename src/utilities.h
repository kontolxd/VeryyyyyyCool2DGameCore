#ifndef UTILITIES_H
#define UTILITIES_H
#include<string>
namespace nya
{
    #ifdef linux
    #include<unistd.h>
    inline std::string getWorkingDirectory()
    {
        char cwd[1024];
        if(getcwd(cwd, sizeof(cwd)) != nullptr)
        {
            return std::string(cwd)+std::string("/");
        }
        return "";
    }
    #elif
    inline std::string getWorkingDirectory()
    {
        return "";
    }
    #endif
}

#endif // UTILITIES_H
