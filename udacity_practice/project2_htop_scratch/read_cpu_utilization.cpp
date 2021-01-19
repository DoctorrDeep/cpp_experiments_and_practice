#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for

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

class CPU_U {
public:
  // The constructor is not necessary.
  // CPU_U(){
  //   read_raw_cpu_stats();
  // };
  double return_cpu_percentage() {
    read_raw_cpu_stats();
    compute_cpu_util();
    return CPU_Percentage;
  }

private:
  double idle = 0.0;
  double iowait = 0.0;
  double irq = 0.0;
  double nice = 0.0;
  double softirq = 0.0;
  double steal = 0.0;
  double system = 0.0;
  double user = 0.0;

  double guest = 0.0;
  double guest_nice = 0.0;

  double previdle = 0.0;
  double previowait = 0.0;
  double prevuser = 0.0;
  double prevnice = 0.0;
  double prevsystem = 0.0;
  double previrq = 0.0;
  double prevsoftirq = 0.0;
  double prevsteal = 0.0;

  double PrevIdle = 0.0;
  double PrevNonIdle = 0.0;
  double PrevTotal = 0.0;
  double Idle = 0.0;
  double NonIdle = 0.0;
  double Total = 0.0;

  double totald = 0.0;
  double idled = 0.0;

  double CPU_Percentage = 0.0;

  void read_raw_cpu_stats();
  void compute_cpu_util();
  void update_prev_values() {
    previdle = idle;
    previowait = iowait;
    prevuser = user;
    prevnice = nice;
    prevsystem = system;
    previrq = irq;
    prevsoftirq = softirq;
    prevsteal = steal;
  }
};

void CPU_U::read_raw_cpu_stats() {
  string cpu, line;
  std::ifstream stream("/proc/stat");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream my_stream(line);
    my_stream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guest >> guest_nice;
  }
}

void CPU_U::compute_cpu_util() {
  // From https://stackoverflow.com/a/23376195
  PrevIdle = previdle + previowait;
  Idle = idle + iowait;

  PrevNonIdle =
      prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  NonIdle = user + nice + system + irq + softirq + steal;

  PrevTotal = PrevIdle + PrevNonIdle;
  Total = Idle + NonIdle;

  // differentiate : actual value minus the previous one
  totald = Total - PrevTotal;
  idled = Idle - PrevIdle;

  CPU_Percentage = ((totald - idled) * 100) / totald;
  update_prev_values();
}

int main() {
  // exp 1: read kernel version
  // cout << ReadKernelVersion() << "\n";

  // exp 2: read accumulated cpu stats raw from file
  // auto util_data{ReadCPUUtilization()};
  // cout << util_data[0] << "\n" << util_data[1] << "\n";

  // exp 3: read and compute accumulated cpu stats from file
  CPU_U cpu_util;

  for (int i = 0; i < 100; i++) {
    cout << i << "    : " << cpu_util.return_cpu_percentage() << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}