#include <chrono>  // std::chrono::seconds
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>  // std::this_thread::sleep_for
#include <vector>

using std::cout;
using std::string;
using std::vector;

float ReadMemUtilization() {
  float avail_mem, tot_mem, temp_mem, percentage_mem;  // all in kB
  string line;

  std::ifstream stream("/proc/meminfo");
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      string mem_stat_name;
      std::istringstream my_stream(line);
      my_stream >> mem_stat_name >> temp_mem;

      if (mem_stat_name == "MemTotal:") {
        tot_mem = temp_mem;
      }
      if (mem_stat_name == "MemAvailable:") {
        avail_mem = temp_mem;
      }
    }
  }

  percentage_mem = ((tot_mem - avail_mem) * 100) / tot_mem;
  return percentage_mem;
}

int main() {
  // exp 3: read and compute mem stats from file
  for (int i = 0; i < 100; i++) {
    cout << i << " seconds from start: " << ReadMemUtilization() << "% used\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}