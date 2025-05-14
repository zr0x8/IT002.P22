#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
#include <vector>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    bool isValid() const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    friend std::istream& operator>>(std::istream& is, Date& date);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

class Time {
private:
    int hour;
    int minute;

public:
    Time();
    Time(int hour, int minute);
    bool isValid() const;
    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    friend std::istream& operator>>(std::istream& is, Time& time);
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

class Flight {
private:
    std::string flightCode;
    Date departureDate;
    Time departureTime;
    std::string origin;
    std::string destination;

public:
    Flight();
    Flight(const std::string& flightCode, const Date& departureDate, 
           const Time& departureTime, const std::string& origin, const std::string& destination);
    
    std::string getFlightCode() const;
    Date getDepartureDate() const;
    Time getDepartureTime() const;
    std::string getOrigin() const;
    std::string getDestination() const;

    static bool isValidFlightCode(const std::string& code);
    static bool isValidLocation(const std::string& location);
    
    friend std::istream& operator>>(std::istream& is, Flight& flight);
    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
    

    bool operator<(const Flight& other) const; // for sorting by date and time
};

class FlightManager {
private:
    std::vector<Flight> flights;

public:
    void addFlight(const Flight& flight);
    void displayAllFlights() const;
    
    std::vector<Flight> searchByFlightCode(const std::string& code) const;
    std::vector<Flight> searchByOrigin(const std::string& origin) const;
    std::vector<Flight> searchByDestination(const std::string& destination) const;
    
    void sortByDepartureDateTime();
    
    std::vector<Flight> getFlightsFromOriginOnDate(const std::string& origin, const Date& date) const;
    int countFlightsBetween(const std::string& origin, const std::string& destination) const;
};

#endif
