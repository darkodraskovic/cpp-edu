#pragma once
#include <cstdint>

void print_game_state(const std::uint32_t player);
unsigned int execute_move(const std::uint32_t player, const char move);
bool is_finished(const std::uint32_t player);
void game();
