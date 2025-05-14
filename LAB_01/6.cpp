#include <iostream>
#include <vector>

using namespace std;

// dung thuat toan kmp

vector<int> getLPS(const vector<int>& pattern) {
  vector<int> lps(pattern.size(), 0);
  int index = 0;
  for (int i = 1; i < pattern.size(); i++) {
    if (pattern[i] == pattern[index]) {
      lps[i] = ++index;
    } else {
      if (index > 0) {
        index = lps[index - 1];
        i--;  // giu nguyen i de check lai
      }
    }
  }
  return lps;
}

void findMatchingPattern(const vector<int>& pattern, const vector<int>& list) {
  vector<int> lps{getLPS(pattern)};
  vector<int> result;
  int i{0}, j{0};
  while (i < list.size()) {
    if (list[i] == pattern[j]) {
      i++;
      j++;
      if (j == pattern.size() - 1) {
        result.push_back(i - j);
        j = lps[j - 1];
      }
    } else {
      if (j > 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
}

int main() {
  int a_length{}, b_length{};
  cout << "Nhap vao do dai cua mang a: ";
  cin >> a_length;
  cout << "\nNhap vao do dai cua mang b: ";
  cin >> b_length;
  vector<int> a(a_length), b(b_length);
  cout << "\nNhap vao cac phan tu cua mang a: ";
  for (int i = 0; i < a_length; i++) {
    cin >> a[i];
  }
  cout << "\nNhap vao cac phan tu cua mang b: ";
  for (int i = 0; i < b_length; i++) {
    cin >> b[i];
  }
  findMatchingPattern(a, b);

  return 0;
}