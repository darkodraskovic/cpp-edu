#include <cstdint>
#include <iostream>

enum class Lane { RIGHT, LEFT, CENTER };

struct Vehicle {
  std::uint32_t id;
  float velocity;
  Lane lane;
};

void print_vehicle_data(const Vehicle& vehicle) {
  std::cout << "Vehicle ID:" << vehicle.id << "\n";
  std::cout << "Vehicle velocity:" << vehicle.velocity << "\n";

  switch (vehicle.lane) {
    case Lane::RIGHT:
      std::cout << "Vehicle lane assoc: Right\n";
      break;
    case Lane::LEFT:
      std::cout << "Vehicle lane assoc: Left\n";
      break;
    case Lane::CENTER:
      std::cout << "Vehicle lane assoc: Center\n";
      break;
    default:
      break;
  }
}

void print_vehicle_data(const Vehicle* vehicle) { print_vehicle_data(*vehicle); }

int main(int argc, char* argv[]) {
  // std::cout << "Hello world! Zzz..."
  //           << "\n";
  const auto current_lane = Lane::RIGHT;
  const auto vehicle1 = Vehicle{.id = 1, .velocity = 55.0f, .lane = current_lane};

  print_vehicle_data(vehicle1);
  print_vehicle_data(&vehicle1);
}
