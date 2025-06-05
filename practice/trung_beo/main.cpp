#include "Parallelogram.h"
#include "Shape.h"
#include "Trapezoid.h"

#include <iostream>
#include <vector>

#define clrscr std::cout << "\033[2J\033[1;1H"

//will defo make an extra managent class for this, but dont have enough time

int main(int argc, char **argv) {
  int n;
  std::cout << "Nhap so luong hinh co tren mat phang: ";
  std::cin >> n;
  std::vector<Shape *> manage(n);
  for (int i = 0; i < n; i++) {
    clrscr;
    do {
      clrscr;
      std::cout << "Hinh ban muon nhap la gi?\n[1] Hinh binh hanh\n[2] Hinh "
                   "thang\nNhap lua chon cua ban: ";
      int choice;
      std::cin >> choice;
      switch (choice) {
      case 1: {
        Parallelogram *p = new Parallelogram;
        manage[i] = p;
        std::cout << "Hay nhap thong tin cua hinh binh hanh (theo dinh dang "
                     "chieucao:canhday:canhben): ";
        std::cin >> *p;
        break;
      }
      case 2: {
        Trapezoid *t = new Trapezoid;
        manage[i] = t;
        std::cout << "Hay nhap thong tin cua hinh thang (theo dinh dang: "
                     "chieucao:daytren:dayduoi:canhtrai:canhphai): ";
        std::cin >> *t;
        break;
      }
      default:
        std::cout << "Nhap sai dinh dang, vui long nhap lai!";
        continue;
      }
      break;
    } while (true);
    clrscr;
  }

  int choice;
  do {
    clrscr;
    std::cout
        << "========Quan li========\n[1] In thong tin va chu vi cua cac "
           "hinh\n[2] In thong tin va dien tich cua cac hinh\n[3] Tinh "
           "tong dien tich cua cac hinh\n[0] Thoat\nNhap lua chon cua ban: ";
    std::cin >> choice;
    switch (choice) {
    case 0:
      break;
    case 1: {
      clrscr;
      for (int i = 0; i < n; i++) {
        std::cout << manage[i]->ToString()
                  << "\nChu vi: " << manage[i]->CalculatePerimeter() << '\n';
      }
      std::cout << "Nhan phim bat ki de tiep tuc!";
      std::cin.ignore();
      std::cin.get();
      break;
    }
    case 2: {
      clrscr;
      for (int i = 0; i < n; i++) {
        std::cout << manage[i]->ToString() << "\nDien tich: " << manage[i]->CalculateArea()
                  << '\n'; // how tf did i forgor this 
      }
      std::cout << "Nhan phim bat ki de tiep tuc!";
      std::cin.ignore();
      std::cin.get();
      break;
    }
    case 3: {
      clrscr;
      double sum{0};
      for (int i = 0; i < n; i++)
        sum += manage[i]->CalculateArea();
      std::cout << "Tong dien tich cua cac hinh la: " << sum;
      std::cout << "\nNhan phim bat ki de tiep tuc!";
      std::cin.ignore();
      std::cin.get();
      break;
    }
    }
  } while (choice != 0);

  for (int i = 0; i < n; i++)
    delete manage[i];
  return 0;
}
