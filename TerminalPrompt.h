/**************************************************
*
*  TerminalPrompt.h
*
*  @author Ryan Morehouse
*  @license MIT
*
*  A class to simplify prompting the user for input
*  from the terminal.
*
  **************************************************/

#ifndef TERMINALPROMPT_H
#define TERMINALPROMPT_h

#include <iostream>
#include <string>

class TerminalPrompt {
  public:
    bool get_bool(std::string *prompt);
    char get_char(std::string *prompt);
    double get_double(std::string *prompt);
    double get_positive_double(std::string *prompt);
    float get_float(std::string *prompt);
    float get_positive_float(std::string *prompt);
    int get_int(std::string *prompt);
    int get_positive_int(std::string *prompt);
    long get_long(std::string *prompt);
    long get_positive_long(std::string *prompt);
    std::string get_string(std::string *prompt);
};

#endif
