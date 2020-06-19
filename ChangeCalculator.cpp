/*********************************************************************

   Change Calculator.cpp

   @author Ryan Morehouse
   @license MIT

   A simple class to encapsulate a calculation of change returned for
   amounts of cash paid.

   *****************************************************************/

#include <math.h>
#include <stdexcept>
#include <string>
#include <sstream>
#include "ChangeCalculator.h"

ChangeCalculator::ChangeCalculator(double cost, double paid) {
  // verify args
  if(cost <= 0 || paid <= 0)
    throw std::invalid_argument("Invalid cost or paid values.");

  // get currency as int values
  this->cost_dollars = static_cast<int>(floor(cost));
  this->cost_cents = static_cast<int>(floor(cost * 100));
  this->cost_cents -= this->cost_dollars * 100;

  this->paid_dollars = static_cast<int>(floor(paid));
  this->paid_cents = static_cast<int>(floor(paid * 100));
  this->paid_cents -= this->paid_dollars * 100;

  // calulate change
  int raw_change = this->paid_dollars * 100 + this->paid_cents;
  raw_change -= (this->cost_dollars * 100 + this->cost_cents);
  this->change_dollars = raw_change / 100;
  this->change_cents = raw_change % 100;


  // flag if payment still owing
  if (paid < cost)
    this->pay_still_owing = true;
  else
    this->pay_still_owing = false;

  // calculate coins
  int change = this->change_cents;
  this->quarters = change / 25;
  change = change % 25;
  this->dimes = change / 10;
  change = change % 10;
  this->nickles = change / 5;
  change = change % 5;
  // no pennies in Canada
  if(change > 2)
    this->nickles++;
}

int ChangeCalculator::get_change_dollars() {
  return this->change_dollars;
}

int ChangeCalculator::get_change_quarters() {
  return this->quarters;
}

int ChangeCalculator::get_change_dimes() {
  return this->dimes;
}

int ChangeCalculator::get_change_nickles() {
  return this->nickles;
}

std::string ChangeCalculator::get_report() {
  std::ostringstream report;
  report << "Total Cost: $" << this->cost_dollars << "." << this->cost_cents;
  report << std::endl;
  report << "Total Paid: $" << this->paid_dollars << "." << this->paid_cents;
  report << std::endl;
  report << "Total Change: $" << this->change_dollars << ".";
  report << this->change_cents << std::endl;

  if(this->pay_still_owing)
    report << "No change due to oustanding balance.\n";
  else {
    report << "Change Amounts:" << std::endl;
    report << "Dollars: " << this->change_dollars << std::endl;
    report << "Quarters: " << this->quarters << std::endl;
    report << "Dimes: " << this->dimes << std::endl;
    report << "Nickles: " << this->nickles << std::endl;
  }
  return report.str();
}

