/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-09-17

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include <cstring>
#include <iomanip>
#include "RideRequest.h"

using namespace std;

namespace sdds {
  RideRequest::RideRequest(const RideRequest& src) {
    *this = src;
  }

  RideRequest& RideRequest::operator=(const RideRequest& src) {
    if (this != &src) {
      strncpy(m_name, src.m_name, maxNameLength + 1);
      m_price = src.m_price;
      m_discountApplied = src.m_discountApplied;

      if (src.m_desc != nullptr) {
        delete[] m_desc;
        m_desc = new char[strlen(src.m_desc) + 1];
        strcpy(m_desc, src.m_desc);
      }
      else {
        m_desc = nullptr;
      }
    }
    return *this;
  }

  RideRequest::~RideRequest() {
    delete[] m_desc;
    m_desc = nullptr;
  }

  void RideRequest::read(istream& is) {
    string tempDesc;
    char discount = 'N';
    
    if (is) {
      is.getline(m_name, maxNameLength + 1, ',');

      // get the description from the input stream
      getline(is, tempDesc, ',');

      if (tempDesc.c_str() != nullptr) {
        delete[] m_desc;
        m_desc = new char[tempDesc.length() + 1];
        strcpy(m_desc, tempDesc.c_str());
      }

      is >> m_price;
      is.ignore(1000, ',');

      is >> discount;
      is.ignore(1000, '\n');

      if (discount == 'Y') {
        m_discountApplied = true;
      }
      else {
        m_discountApplied = false;
      }
    }
  }

  void RideRequest::display() {
    static int counter = 1;
    double taxPrice = m_price + (m_price * g_taxrate);
    double discountPrice = taxPrice - g_discount;

    cout.width(2);
    cout << left << setw(2) << counter++ << ". ";
    if (m_name[0] == '\0') {
      cout << "No Ride Request" << endl;
    }
    else {
      cout << left << setw(maxNameLength) << m_name << "|";
      cout << left << setw(maxDescLength) << m_desc << "|";
      cout << left << fixed << setw(12) << setprecision(2) << taxPrice << "|";
      if (m_discountApplied) {
        cout << right << fixed << setw(13) << discountPrice;
      }
      cout << endl;
    }
  }
}
