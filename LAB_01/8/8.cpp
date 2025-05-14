#include "Flight.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

void clearInputBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
  std::cout << "\n===== MENU =====\n";
  std::cout << "1. Them chuyen bay moi\n";
  std::cout << "2. Hien thi tat ca chuyen bay\n";
  std::cout << "3. Tim kiem ma so chuyen bay\n";
  std::cout << "4. Tim kiem noi khoi hanh\n";
  std::cout << "5. Tim kiem noi ha canh\n";
  std::cout << "6. Sap xep chuyen bay theo thoi gian\n";
  std::cout << "7. Hien thi chuyen bay trong khoang thoi gian nhat dinh\n";
  std::cout << "8. Dem so luong chuyen bay o 2 noi\n";
  std::cout << "0. Thoat\n";
  std::cout << "Nhap lua chon cua ban: ";
}

void displayFlights(const std::vector<Flight> &flights,
                    const std::string &message) {
  std::cout << "\n" << message << "\n";
  if (flights.empty()) {
    std::cout << "Khong tim thay chuyen bay.\n";
    return;
  }

  for (size_t i = 0; i < flights.size(); ++i) {
    std::cout << "Chuyen bay thu " << (i + 1) << ":\n";
    std::cout << flights[i] << "\n\n";
  }
}

int main() {
  FlightManager manager;
  int choice;

  do {
    displayMenu();
    if (!(std::cin >> choice)) {
      std::cout << "Khong hop le! Vui long nhap lai\n";
      clearInputBuffer();
      continue;
    }

    clearInputBuffer();

    switch (choice) {
    case 0:
      std::cout << "Tam biet\n";
      break;

    case 1: {
      Flight newFlight;
      std::cout << "\nBat dau them chuyen bay moi:\n";
      if (std::cin >> newFlight) {
        manager.addFlight(newFlight);
        std::cout << "Thanh cong!\n";
      } else {
        std::cout << "Da xay ra loi. Vui long thu lai\n";
        clearInputBuffer();
      }
      break;
    }

    case 2:
      std::cout << "\n===== Danh sach chuyen bay =====\n";
      manager.displayAllFlights();
      break;

    case 3: {
      std::string code;
      std::cout << "Nhap ma so chuyen bay: ";
      std::cin >> code;
      auto results = manager.searchByFlightCode(code);
      displayFlights(results, "Ket qua cho chuyen bay: " + code);
      break;
    }

    case 4: {
      std::string origin;
      std::cout << "Nhap noi khoi hanh: ";
      std::getline(std::cin, origin);
      auto results = manager.searchByOrigin(origin);
      displayFlights(results, "Ket qua cho chuyen bay tu: " + origin);
      break;
    }

    case 5: {
      std::string destination;
      std::cout << "Nhap noi den: ";
      std::getline(std::cin, destination);
      auto results = manager.searchByDestination(destination);
      displayFlights(results, "Ket qua cho chuyen bay den: " + destination);
      break;
    }

    case 6:
      manager.sortByDepartureDateTime();
      std::cout << "Da sap xep thanh cong!\n";
      manager.displayAllFlights();
      break;

    case 7: {
      std::string origin;
      Date date;
      std::cout << "Nhap noi khoi hanh: ";
      std::getline(std::cin, origin);
      std::cout << "Nhap ngay khoi hanh (theo dinh dang DD/MM/YYYY): ";
      if (std::cin >> date) {
        auto results = manager.getFlightsFromOriginOnDate(origin, date);
        std::stringstream ss;
        ss << "Chuyen bay tu " << origin << " vao luc " << date;
        displayFlights(results, ss.str());
      } else {
        std::cout << "Khong hop le!\n";
        clearInputBuffer();
      }
      break;
    }

    case 8: {
      std::string origin, destination;
      std::cout << "Nhap noi khoi hanh: ";
      std::getline(std::cin, origin);
      std::cout << "Nhap noi den: ";
      std::getline(std::cin, destination);
      int count = manager.countFlightsBetween(origin, destination);
      std::cout << "So chuyen bay tu " << origin << " den " << destination
                << ": " << count << "\n";
      break;
    }

    default:
      std::cout << "Lua chon khong hop le! Vui long thu lai\n";
    }
  } while (choice != 0);

  return 0;
}
