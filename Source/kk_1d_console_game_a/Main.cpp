#include <iostream>

int main(int argc, char *argv[]) {
  const unsigned int LEN_X = 10;
  const unsigned int START = 0;
  const unsigned int GOAL = 9;
  const char LEFT = 'a';
  const char RIGHT = 'd';

  unsigned int player = 0;
  char move = 0;

  while (true) {
    if (player == GOAL) {
      break;
    }

    for (unsigned int i = 0; i < LEN_X; i++) {
      if (i == player) {
        std::cout << "@";
      } else if (i == START || i == GOAL) {
        std::cout << "|";
      } else {
        std::cout << ".";
      }
    }

    std::cin >> move;
    if (move == LEFT && player > START) {
      player--;
    } else if (move == RIGHT && player < GOAL) {
      player++;
    } else {
      std::cout << "can't move" << std::endl;
    }
  }
}
