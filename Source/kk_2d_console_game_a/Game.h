#pragma once
#include <cstdint>
#include <iostream>

struct Position {
  std::uint32_t x = 0;
  std::uint32_t y = 0;
  bool operator==(const Position& rhs) const;
};

enum class Input {
  INVALID,
  LEFT = 'a',
  RIGHT = 'd',
  UP = 'w',
  DOWN = 's',
};

std::istream& operator>>(std::istream& is, Input& move);

void print_game_state(const Position& player);
void execute_move(Position& player, Input move);
bool is_finished(const Position& player);
void game();
