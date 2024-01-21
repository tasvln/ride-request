/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-09-17

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>

// two variables will be accessed when a new day of rides starts from the main function.
extern double g_taxrate;
extern double g_discount;

namespace sdds {
  // maximum length of name and details
  const int maxNameLength = 10;
  const int maxDescLength = 25;

  class RideRequest {
    char m_name[maxNameLength + 1] = { '\0' };
    char* m_desc = nullptr;
    double m_price = 0.0;
    bool m_discountApplied = false;
  public:
    RideRequest() {};

    // copy constructor
    RideRequest(const RideRequest& src);

    // copy assignment operator
    RideRequest& operator=(const RideRequest& src);

    // destructor
    ~RideRequest();

    // read(): a modifier that receives an istream reference.
    void read(std::istream& is);

    // display(): a query that displays to the screen the content of an Ride Request
    void display();
  };
}

#endif