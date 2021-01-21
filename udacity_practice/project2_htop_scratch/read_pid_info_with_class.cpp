#include <dirent.h>
#include <unistd.h>

#include <algorithm> // for all_of
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#define hertz sysconf(_SC_CLK_TCK)

using std::cout;
using std::stof;
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

// BONUS: Update this to use std::filesystem
vector<int> Pids() {
  vector<int> pids;
  string procdir = "/proc";
  DIR *directory = opendir(procdir.c_str());
  struct dirent *file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

unordered_map<int, string> Uid_User_Map() {
  unordered_map<int, string> uid_user_map;
  string user_file = "/etc/passwd";
  string line;
  string user, spacer;
  int uid;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> user >> spacer >> uid) {
        uid_user_map[uid] = user;
      }
    }
  }
  return uid_user_map;
}

long SystemUpTime() {
  long uptime;
  string line;
  string fileloc = "/proc/uptime";
  std::ifstream stream(fileloc);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> uptime;
  }
  return uptime;
}

class Process {
public:
  Process(int pid,
          unordered_map<int, string> uid_user_map); // check if this is allowed

  int Pid();
  string User();
  string Command();
  float CpuUtilization();
  string Ram();
  long int UpTime();
  void Cpu_Mem_Utime();

private:
  int pid;
  string user;
  float cpu_util;
  string ram;
  long int uptime;
  string command;
  unordered_map<int, string> uid_user_map;
};

Process::Process(int pid, unordered_map<int, string> uid_user_map)
    : pid(pid), uid_user_map(uid_user_map) {
  Cpu_Mem_Utime();
  User();
  Command();
};

int Process::Pid() { return pid; };

string Process::User() {
  string status_file = "/proc/" + to_string(pid) + "/status";
  string line;
  string stat_name;
  int an_id;
  std::ifstream filestream(status_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> stat_name >> an_id) {
        if (stat_name == "Uid:") {
          user = uid_user_map[an_id];
          return user;
        }
      }
    }
  }
  return " ";
};

string Process::Command() {
  string user_file = "/proc/" + to_string(pid) + "/cmdline";
  string line;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      command = line;
      return line;
    }
  }
  return " ";
};

float Process::CpuUtilization() {
  // Cpu_Mem_Utime();
  return cpu_util;
};

string Process::Ram() {
  // Cpu_Mem_Utime();
  return ram;
};

long int Process::UpTime() {
  // Cpu_Mem_Utime();
  return uptime;
};

void Process::Cpu_Mem_Utime() {
  // https://man7.org/linux/man-pages/man5/proc.5.html
  // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  // int hertz = sysconf(_SC_CLK_TCK); // convert to compiletime const
  string user_file = "/proc/" + to_string(pid) + "/stat";
  string line, stat2, stat3;
  double stat1, stat4, stat5, stat6, stat7, stat8, stat9, stat10,
      stat11, stat12, stat13, stat14, stat15, stat16, stat17, stat18, stat19,
      stat20, stat21, stat22, stat23, stat24, stat25, stat26, stat27, stat28,
      stat29, stat30, stat31, stat32, stat33, stat34, stat35, stat36, stat37,
      stat38, stat39, stat40, stat41, stat42, stat43, stat44, stat45, stat46,
      stat47, stat48, stat49, stat50, stat51, stat52;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> stat1 >> stat2 >> stat3 >> stat4 >> stat5 >> stat6 >>
          stat7 >> stat8 >> stat9 >> stat10 >> stat11 >> stat12 >> stat13 >>
          stat14 >> stat15 >> stat16 >> stat17 >> stat18 >> stat19 >> stat20 >>
          stat21 >> stat22 >> stat23 >> stat24 >> stat25 >> stat26 >> stat27 >>
          stat28 >> stat29 >> stat30 >> stat31 >> stat32 >> stat33 >> stat34 >>
          stat35 >> stat36 >> stat37 >> stat38 >> stat39 >> stat40 >> stat41 >>
          stat42 >> stat43 >> stat44 >> stat45 >> stat46 >> stat47 >> stat48 >>
          stat49 >> stat50 >> stat51 >> stat52;

      uptime = stat14 + stat15 + stat16 + stat17;
      int temp_ram = stat23 / 1000000;
      ram = to_string(temp_ram) + " MB";
      double temp_seconds = SystemUpTime() - (stat22 / hertz);
      cpu_util = 100 * ((uptime / hertz) / temp_seconds);
    }
  }
}

int main() {
  auto pids = Pids();
  auto uid_user_map = Uid_User_Map();

  vector<Process> processes;
  for (auto pid : pids) {
    Process temp_process(pid, uid_user_map);
    processes.push_back(temp_process);
  }

  for (auto process : processes) {
    cout << process.Pid() << "\t\t";
    cout << process.User() << "\t\t";
    cout << process.CpuUtilization() << "\t\t";
    cout << process.Ram() << "\t\t";
    cout << process.UpTime() << "\t\t";
    string smallcmd = process.Command();
    cout << smallcmd.substr(0, 30) << "\n";
  }

  // Process process(19088, uid_user_map);
  // cout << process.Pid() << "\t\t";
  // cout << process.User() << "\t\t";
  // cout << process.CpuUtilization() << "\t\t";
  // cout << process.Ram() << "\t\t";
  // cout << process.UpTime() << "\t\t";
  // string smallcmd = process.Command();
  // cout << smallcmd.substr(0, 30) << "\n";
}