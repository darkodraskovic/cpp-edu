#include <cassert>
#include <iostream>
#include <map>

using std::map;
using std::pair;
using std::string;

// {name, {age, weight}}
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

int main(int argc, char *argv[]) {
  Friends friends{{"Peter", {22, 78}}, {"Yellow", {25, 98}}, {"Red", {19, 102}}, {"Green", {32, 60}}};

  assert(get_oldest_friend(friends) == "Green");
  assert(get_heaviest_friend(friends) == "Red");
}
