#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

typedef map<string, pair<int, int>> Friends;

string get_oldest_friend(const Friends &friends) {
  string oldest = friends.begin()->first;
  for (auto it = ++friends.begin(); it != friends.end(); it++) {
    if (it->second.first > friends.at(oldest).first) {
      oldest = it->first;
    }
  }
  return oldest;
}

string get_heaviest_friend(const Friends &friends) {
  string heaviest = friends.begin()->first;
  for (auto it = ++friends.begin(); it != friends.end(); it++) {
    if (it->second.second > friends.at(heaviest).second) {
      heaviest = it->first;
    }
  }
  return heaviest;
}

bool is_palindrom(const std::string &str) {
  if (!str.length()) {
    return true;
  }
  if (str[0] == str[str.length() - 1]) {
    return is_palindrom(str.substr(1, str.length() - 2));
  }
  return false;
}

bool is_palindrom2(const std::string &str) {
  return std::string(str.crbegin(), str.crend()) == str;
}

bool is_in_string(const std::string &str, const std::string &sub_str) {
  int str_idx = 0;
  int sub_str_idx = 0;
  while (str_idx != str.length()) {
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

  for (std::string::const_iterator it = str.cbegin();
       it != str.cend() - (sub_str_len - 1); ++it) {
    const std::string check_str(it, it + 2);

    if (check_str == sub_str) return true;
  }

  return false;
}

// unsigned int str_concat_exponent(const std::string& str, const std::string&
// base);

int main(int argc, char *argv[]) {
  Friends friends{{"Peter", {22, 78}},
                  {"Yellow", {25, 98}},
                  {"Red", {19, 102}},
                  {"Green", {32, 60}}};
  // std::cout << get_oldest_friend(friends) << "\n";
  // std::cout << get_heaviest_friend(friends) << "\n";

  // Aufgabe 1
  std::string str1 = "mrannarm";
  std::string str3 = "mrannarmz";

  if (is_palindrom2(str1)) {
    std::cout << "Ist ein Palindrom!" << std::endl;
  } else {
    std::cout << "Ist kein Palindrom!" << std::endl;
  }

  // Aufgabe 2
  // std::string str2 = "HALLOTOLOTTLOTTOHAL";
  // std::string sub_str = "LOTTO";
  std::string str2 = "abbbbbe";
  std::string sub_str = "bbbe";

  if (is_in_string(str2, sub_str)) {
    std::cout << "Ist im String!" << std::endl;
  } else {
    std::cout << "Ist nicht im String!" << std::endl;
  }

  // // Aufgabe 3
  // std::string str3 = "abab";
  // std::string base = "ab";

  // unsigned int exponent = str_concat_exponent(str3, base);
  // std::cout << "Exponent: " << exponent << std::endl;

  return 0;
}
