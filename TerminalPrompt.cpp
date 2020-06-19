/***************************************************
*
*  TerminalPrompt.cpp
*
*  @author Ryan Morehouse
*  @license MIT
*
*  A class to simplify prompting the user for input
*  from the terminal.
*
  *************************************************/

#include <iostream>
#include <string>
#include <limits>
#include "TerminalPrompt.h"

bool TerminalPrompt::get_bool(std::string *prompt) {
  char c;
  while(true) {
    std:: cout << *prompt << ": ";
    if (std::cin >> c) {
      if(c == 'y' || c == 'Y')
        return true;
      else if(c == 'n' || c == 'N')
        return false;
      else {
        std::cout << "Input y or n, please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
    }
  }
}

char TerminalPrompt::get_char(std::string *prompt) {
  char c;
  while(true) {
    std::cout << *prompt << ": ";
    if(std::cin >> c)
      return c;
    else {
      std::cout << "Invalid character input, please try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}


double TerminalPrompt::get_double(std::string *prompt) {
  double d;
  while(true) {
    std::cout << *prompt << ": ";
    if (std::cin >> d)
      return d;
    else {
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}

double TerminalPrompt::get_positive_double(std::string *prompt) {
  double d = get_double(prompt);
  while(d < 0) {
    std::cout << "Input must be positive. Please try again.\n";
    d = get_double(prompt);
  }
  return d;
}

float TerminalPrompt::get_float(std::string *prompt) {
  float f;
  while(true) {
    std::cout << *prompt << ": ";
    if (std::cin >> f)
      return f;
    else {
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}

float TerminalPrompt::get_positive_float(std::string *prompt) {
  float f = get_float(prompt);
  while(f < 0) {
    std::cout << "Input must be positive. Please try again.\n";
    f = get_float(prompt);
  }
  return f;
}

long TerminalPrompt::get_long(std::string *prompt) {
  long l;
  while(true) {
    std::cout << *prompt << ": ";
    if (std::cin >> l)
      return l;
    else {
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}

long TerminalPrompt::get_positive_long(std::string *prompt) {
  long l = get_long(prompt);
  while(l< 0) {
    std::cout << "Input must be positive. Please try again.\n";
    l = get_long(prompt);
  }
  return l;
}

int TerminalPrompt::get_int(std::string *prompt) {
  int i;
  while(true) {
    std::cout << *prompt << ": ";
    if (std::cin >> i)
      return i;
    else {
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}

int TerminalPrompt::get_positive_int(std::string *prompt) {
  int i = get_int(prompt);
  while(i< 0) {
    std::cout << "Input must be positive. Please try again.\n";
    i = get_int(prompt);
  }
  return i;
}

std::string TerminalPrompt::get_string(std::string *prompt) {
  std::string s;
  while(true) {
    std::cout << *prompt << ": ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    if(getline(std::cin, s))
      return s;
    else{
      std::cout << "Invalid input, try again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
}


