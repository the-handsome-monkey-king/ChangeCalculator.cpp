/******************************************

  test.cpp

  @author Ryan Morehouse
  @license MIT

  A test of the ChangeCalculator class.

  ****************************************/

#include <string>
#include <iostream>
#include "ChangeCalculator.h"
#include "TerminalPrompt.h"

int main() {
  double cost, pay;
  TerminalPrompt term;

  std::string prompt = "Enter the cost (without dollar sign)";
  cost = term.get_positive_double(&prompt);
  prompt = "Enter the payment (without dollar sign)";
  pay = term.get_positive_double(&prompt);

  ChangeCalculator calc(cost, pay);
  std::cout << calc.get_report();

  return 0;
}
