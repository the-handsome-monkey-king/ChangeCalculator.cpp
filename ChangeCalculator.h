/*********************************************************************
*
*   ChangeCalculator.h
*
*   @author Ryan Morehouse
*   @license MIT
*
*   A simple class to encapsulate a calculation of change returned for
*   larger amounts of cash paid.
*
   *******************************************************************/

#ifndef CHANGECALCULATOR_H
#define CHANGECALCULATOR_H

#include <string>

class ChangeCalculator {
  private:
    int cost_dollars, cost_cents;
    int paid_dollars, paid_cents;
    int change_dollars, change_cents;
    bool pay_still_owing;
    int quarters, dimes, nickles;

  public:
    ChangeCalculator(double cost, double paid);
    int get_change_dollars();
    int get_change_quarters();
    int get_change_dimes();
    int get_change_nickles();
    std::string get_report();
};

#endif
