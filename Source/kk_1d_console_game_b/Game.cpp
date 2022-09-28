#include "Game.h"

#include <iostream>

// the "anonymous" namespace means that these variables can be used only in this
// compilation unit (file), i.e. they are invisible from the outside
namespace {
constexpr static std::uint32_t LEN_X = 10U;
constexpr static std::uint32_t START = 0U;
constexpr static std::uint32_t GOAL = 9U;

constexpr static char LEFT = 'a';
constexpr static char RIGHT = 'd';
}  // namespace

void print_game_state(const std::uint32_t player) {
  for (unsigned int i = 0; i < LEN_X; i++) {
    if (i == player) {
      std::cout << "@";
    } else if (i == START || i == GOAL) {
      std::cout << "|";
    } else {
      std::cout << ".";
    }
  }
}

unsigned int execute_move(const std::uint32_t player, const char move) {
  if (move == LEFT && player > START) {
    return player - 1;
  } else if (move == RIGHT && player < GOAL) {
    return player + 1;
  } else {
    std::cout << "can't move" << std::endl;
    return player;
  }
}

bool is_finished(const std::uint32_t player) { return player == GOAL; }

void game() {
  unsigned int player = 0;
  char move = 0;

  while (true) {
    if (is_finished(player)) {
      break;
    }

    print_game_state(player);

    std::cin >> move;
    player = execute_move(player, move);
  }
}
