/*  macroPP_error_exception.h
    Exception class for file_parser
    CS530 Fall 2016
    Alan Riggins
*/

#ifndef MACROPP_ERROR_EXCEPTION_H
#define MACROPP_ERROR_EXCEPTION_H

#include <string>

using namespace std;

class macroPP_error_exception {

public:
    macroPP_error_exception(string s) {
        message = s;
    }

    macroPP_error_exception() {
        message = "An error has occurred";
    }

    string getMessage() {
        return message;
    }

private:
    string message;
};

#endif
