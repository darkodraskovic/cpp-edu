#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::string;

bool is_palindrom(const std::string &str) {
  if (!str.length()) {
    return true;
  }
  if (str[0] == str[str.length() - 1]) {
    return is_palindrom(str.substr(1, str.length() - 2));
  }
  return false;
}

bool is_palindrom2(const std::string &str) { return std::string(str.crbegin(), str.crend()) == str; }

bool is_in_string(const std::string &str, const std::string &sub_str) {
  int str_idx = 0;
  int sub_str_idx = 0;
  while (str_idx < str.length()) {
    if (str[str_idx] == sub_str[sub_str_idx]) {
      sub_str_idx++;
      if (sub_str_idx == sub_str.length()) return true;
    } else {
      str_idx -= sub_str_idx;
      sub_str_idx = 0;
    }
    str_idx++;
  }
  return false;
};

bool is_in_string2(const std::string &str, const std::string &sub_str) {
  std::size_t str_len = str.length();
  std::size_t sub_str_len = sub_str.length();

  if (str_len < sub_str_len) return false;

  for (std::string::const_iterator it = str.cbegin(); it != str.cend() - (sub_str_len - 1); ++it) {
    const std::string check_str(it, it + sub_str_len);

    if (check_str == sub_str) return true;
  }

  return false;
}

// unsigned int str_concat_exponent(const std::string& str, const std::string&
// base);

int main(int argc, char *argv[]) {
  // Aufgabe 1
  std::string palin_str_1 = "mrannarm";
  std::string palin_str_2 = "mrannarmz";

  assert(is_palindrom(palin_str_1));
  assert(!is_palindrom(palin_str_2));
  assert(is_palindrom2(palin_str_1));
  assert(!is_palindrom(palin_str_2));

  // Aufgabe 2
  std::string sup_str_1 = "abbbbbe";
  std::string sub_str_1 = "bbbe";
  assert(is_in_string(sup_str_1, sub_str_1));
  assert(is_in_string2(sup_str_1, sub_str_1));
  std::string sup_str_2 = "HALLOTOLOTTLOTTOHAL";
  std::string sub_str_2 = "LOTTO";
  assert(is_in_string(sup_str_2, sub_str_2));
  assert(is_in_string2(sup_str_2, sub_str_2));

  // // Aufgabe 3
  // std::string str3 = "abab";
  // std::string base = "ab";

  // unsigned int exponent = str_concat_exponent(str3, base);
  // std::cout << "Exponent: " << exponent << std::endl;

  return 0;
}
