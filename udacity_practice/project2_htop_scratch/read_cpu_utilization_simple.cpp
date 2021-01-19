#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

string ReadKernelVersion() {
  string os, version, kernel;
  string line;
  std::ifstream stream("/proc/version");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream my_stream(line);
    my_stream >> os >> version >> kernel;
  }
  return kernel;
}

vector<string> ReadCPUUtilization() {
  string user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  string cpu, line;
  vector<string> util_data;

  std::ifstream stream("/proc/stat");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream my_stream(line);
    my_stream >> cpu >> user >> nice;
    util_data = {line, user};
  }

  return util_data;
}

int main() {
  // exp 1: read kernel version
  cout << "Kernel Version: " << ReadKernelVersion() << "\n\n";

  // exp 2: read accumulated cpu stats raw from file
  auto util_data{ReadCPUUtilization()};
  cout << util_data[0] << "\n" << util_data[1] << "\n\n";
}