#include "exception.hpp"

#include <cstdio>
#include <cstring>

Exception::Exception(const char* msg, const char* file, int line) {
    snprintf(this->fullMsg, MSG_MAX_LENGTH, "%s : %s", "OpenXr Exception", msg);
    if (nullptr != file && 0 < line) {
        snprintf(this->fullMsg, MSG_MAX_LENGTH, "%s (%s:%d)", this->fullMsg, file, line);
    }
}

Exception::~Exception() {

}

const char* Exception::what() const {
    return this->fullMsg;
}