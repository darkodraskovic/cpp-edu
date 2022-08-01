#include "Game.h"

#include <iostream>

void print_game_state(unsigned int player) {
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

unsigned int execute_move(unsigned int player, char move) {
  if (move == LEFT && player > START) {
    return player - 1;
  } else if (move == RIGHT && player < GOAL) {
    return player + 1;
  } else {
    std::cout << "can't move" << std::endl;
    return player;
  }
}

bool is_finished(unsigned int player) { return player == GOAL; }

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
