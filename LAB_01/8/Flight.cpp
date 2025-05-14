#include "Flight.h"
#include <algorithm>
#include <cctype>
#include <iomanip>

Date::Date() : day(1), month(1), year(1970) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

bool Date::isValid() const {
  if (month < 1 || month > 12)
    return false;

  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // nam nhuan
  if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    daysInMonth[2] = 29;

  return day >= 1 && day <= daysInMonth[month];
}

bool Date::operator<(const Date &other) const {
  if (year != other.year)
    return year < other.year;
  if (month != other.month)
    return month < other.month;
  return day < other.day;
}

bool Date::operator==(const Date &other) const {
  return day == other.day && month == other.month && year == other.year;
}

std::istream &operator>>(std::istream &is, Date &date) {
  char delimiter;
  is >> date.day >> delimiter;
  if (delimiter != '/')
    is.setstate(std::ios::failbit);
  is >> date.month >> delimiter;
  if (delimiter != '/')
    is.setstate(std::ios::failbit);
  is >> date.year;

  if (!date.isValid())
    is.setstate(std::ios::failbit);

  return is;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
  os << std::setw(2) << std::setfill('0') << date.day << "/" << std::setw(2)
     << std::setfill('0') << date.month << "/" << date.year;
  return os;
}

Time::Time() : hour(0), minute(0) {}

Time::Time(int hour, int minute) : hour(hour), minute(minute) {}

bool Time::isValid() const {
  return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59;
}

bool Time::operator<(const Time &other) const {
  if (hour != other.hour)
    return hour < other.hour;
  return minute < other.minute;
}

bool Time::operator==(const Time &other) const {
  return hour == other.hour && minute == other.minute;
}

std::istream &operator>>(std::istream &is, Time &time) {
  char delimiter;
  is >> time.hour >> delimiter;
  if (delimiter != ':')
    is.setstate(std::ios::failbit);
  is >> time.minute;

  if (!time.isValid())
    is.setstate(std::ios::failbit);

  return is;
}

std::ostream &operator<<(std::ostream &os, const Time &time) {
  os << std::setw(2) << std::setfill('0') << time.hour << ":" << std::setw(2)
     << std::setfill('0') << time.minute;
  return os;
}

Flight::Flight() {}

Flight::Flight(const std::string &flightCode, const Date &departureDate,
               const Time &departureTime, const std::string &origin,
               const std::string &destination)
    : flightCode(flightCode), departureDate(departureDate),
      departureTime(departureTime), origin(origin), destination(destination) {}

std::string Flight::getFlightCode() const { return flightCode; }
Date Flight::getDepartureDate() const { return departureDate; }
Time Flight::getDepartureTime() const { return departureTime; }
std::string Flight::getOrigin() const { return origin; }
std::string Flight::getDestination() const { return destination; }

bool Flight::isValidFlightCode(const std::string &code) {

  if (code.length() > 5 || code.empty())
    return false;

  for (char c : code) {
    if (!std::isalnum(c))
      return false;
  }

  return true;
}

bool Flight::isValidLocation(const std::string &location) {

  if (location.length() > 20 || location.empty())
    return false;

  for (char c : location) {
    if (!std::isalpha(c) && c != ' ' && c != '.')
      return false;
  }

  return true;
}

std::istream &operator>>(std::istream &is, Flight &flight) {
  std::string code, orig, dest;
  Date date;
  Time time;

  std::cout << "Nhap ma so chuyen bay (toi da 5 ki tu chu va so): ";
  is >> code;
  if (!Flight::isValidFlightCode(code)) {
    std::cout << "Khong hop le!\n";
    is.setstate(std::ios::failbit);
    return is;
  }
  flight.flightCode = code;

  std::cout << "Nhap ngay khoi hanh (theo dinh dang DD/MM/YYYY): ";
  is >> date;
  if (is.fail()) {
    std::cout << "Khong hop le!\n";
    is.clear();
    is.ignore(256, '\n');
    is.setstate(std::ios::failbit);
    return is;
  }
  flight.departureDate = date;

  std::cout << "Nhap thoi gian khoi hanh (theo dinh dang HH:MM): ";
  is >> time;
  if (is.fail()) {
    std::cout << "Khong hop le!\n";
    is.clear();
    is.ignore(256, '\n');
    is.setstate(std::ios::failbit);
    return is;
  }
  flight.departureTime = time;

  is.ignore(); // Clear newline
  std::cout << "Nhap noi khoi hanh (toi da 20 ki tu): ";
  std::getline(is, orig);
  if (!Flight::isValidLocation(orig)) {
    std::cout << "Invalid origin format!\n";
    is.setstate(std::ios::failbit);
    return is;
  }
  flight.origin = orig;

  std::cout << "Nhap noi den (toi da 20 ki tu): ";
  std::getline(is, dest);
  if (!Flight::isValidLocation(dest)) {
    std::cout << "Invalid destination format!\n";
    is.setstate(std::ios::failbit);
    return is;
  }
  flight.destination = dest;

  return is;
}

std::ostream &operator<<(std::ostream &os, const Flight &flight) {
  os << "Chuyen bay: " << flight.flightCode << "\n"
     << "Khoi hanh: " << flight.departureDate << " vao luc "
     << flight.departureTime << "\n"
     << "Lo trinh bay: " << flight.origin << " -> " << flight.destination;
  return os;
}

bool Flight::operator<(const Flight &other) const {
  if (!(departureDate == other.departureDate))
    return departureDate < other.departureDate;
  return departureTime < other.departureTime;
}

// Flight Manager implementation
void FlightManager::addFlight(const Flight &flight) {
  flights.push_back(flight);
}

void FlightManager::displayAllFlights() const {
  if (flights.empty()) {
    std::cout << "Khong tim thaychuyen bay hop le\n";
    return;
  }

  for (size_t i = 0; i < flights.size(); ++i) {
    std::cout << "Chuyen bay thu " << (i + 1) << ":\n";
    std::cout << flights[i] << "\n\n";
  }
}

std::vector<Flight>
FlightManager::searchByFlightCode(const std::string &code) const {
  std::vector<Flight> result;
  for (const auto &flight : flights) {
    if (flight.getFlightCode() == code) {
      result.push_back(flight);
    }
  }
  return result;
}

std::vector<Flight>
FlightManager::searchByOrigin(const std::string &origin) const {
  std::vector<Flight> result;
  for (const auto &flight : flights) {
    if (flight.getOrigin() == origin) {
      result.push_back(flight);
    }
  }
  return result;
}

std::vector<Flight>
FlightManager::searchByDestination(const std::string &destination) const {
  std::vector<Flight> result;
  for (const auto &flight : flights) {
    if (flight.getDestination() == destination) {
      result.push_back(flight);
    }
  }
  return result;
}

void FlightManager::sortByDepartureDateTime() {
  std::sort(flights.begin(), flights.end());
}

std::vector<Flight>
FlightManager::getFlightsFromOriginOnDate(const std::string &origin,
                                          const Date &date) const {
  std::vector<Flight> result;
  for (const auto &flight : flights) {
    if (flight.getOrigin() == origin && flight.getDepartureDate() == date) {
      result.push_back(flight);
    }
  }
  return result;
}

int FlightManager::countFlightsBetween(const std::string &origin,
                                       const std::string &destination) const {
  int count = 0;
  for (const auto &flight : flights) {
    if (flight.getOrigin() == origin &&
        flight.getDestination() == destination) {
      count++;
    }
  }
  return count;
}
