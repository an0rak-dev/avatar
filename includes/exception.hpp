#pragma once

#include <exception>

#define MSG_MAX_LENGTH 1024

#ifdef DEBUG
#define XRASSERT(resultCode, msg) if (XR_FAILED(resultCode)) throw Exception(msg, __FILE__, __LINE__)
#else
#define XRASSERT(resultCode, msg) if (XR_FAILED(resultCode)) throw Exception(msg)
#endif

class Exception : public std::exception {
    public:
        Exception(const char* msg, const char* file = nullptr, int line = 0);
        virtual ~Exception();
        const char* what() const throw();

    private:
        char fullMsg[MSG_MAX_LENGTH] = { '\0' };
};