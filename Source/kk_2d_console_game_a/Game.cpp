#include "Game.h"

// the "anonymous" namespace means that these variables can be used only in this
// compilation unit (file), i.e. they are invisible from the outside
namespace {
constexpr static std::uint32_t LEN_X = 5u;
constexpr static std::uint32_t LEN_Y = 5u;
constexpr static auto START = Position{.x = 0, .y = 0};
constexpr static auto GOAL = Position{.x = LEN_X - 1, .y = LEN_Y - 1};
}  // namespace

bool Position::operator==(const Position& rhs) const {
  return this->x == rhs.x && this->y == rhs.y;
}

void print_game_state(const Position& player) {
  for (unsigned int y = 0; y < LEN_Y; y++) {
    for (unsigned int x = 0; x < LEN_X; x++) {
      Position position = {x, y};
      if (position == player) {
        std::cout << "@";
      } else if (position == START || position == GOAL) {
        std::cout << "|";
      } else {
        std::cout << ".";
      }
    }
    std::cout << "\n";
  }
}

void execute_move(Position& player, Input move) {
  if (move == Input::LEFT && player.x > 0) {
    player.x--;
  } else if (move == Input::RIGHT && player.x < LEN_X - 1) {
    player.x++;
  } else if (move == Input::UP && player.y > 0) {
    player.y--;
  } else if (move == Input::DOWN && player.y < LEN_Y - 1) {
    player.y++;
  } else {
    std::cout << "can't move" << std::endl;
  }
}

bool is_finished(const Position& player) { return player == GOAL; }

std::istream& operator>>(std::istream& is, Input& move) {
  char input;
  is >> input;
  switch (input) {
    case 'a':
      move = Input::LEFT;
      break;
    case 'd':
      move = Input::RIGHT;
      break;
    case 'w':
      move = Input::UP;
      break;
    case 's':
      move = Input::DOWN;
      break;
    default:
      move = Input::INVALID;
      break;
  }
  return is;
}

void game() {
  Position player = START;
  Input move = Input::INVALID;

  print_game_state(player);

  bool run = true;
  while (run) {
    // process input

    // std::cin >> move;
    // execute_move(player, move);

    char move_char;
    std::cin >> move_char;

    // process mechanics
    execute_move(player, static_cast<Input>(move_char));

    if (is_finished(player)) {
      std::cout << "You've reached the exit\n";
      run = false;
    }

    // draw
    print_game_state(player);
  }
}
