#include <dirent.h>
#include <unistd.h>

#include <algorithm>  // for all_of
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

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
  DIR* directory = opendir(procdir.c_str());
  struct dirent* file;
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

string Cmdline(const int& process_id) {
  string user_file = "/proc/" + to_string(process_id) + "/cmdline";
  string line;
  std::ifstream filestream(user_file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      return line;
    }
  }
  return " ";
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

unordered_map<int, vector<string>> Pid_Data() {
  unordered_map<int, vector<string>> pid_data;
  auto uid_user_map = Uid_User_Map();

  for (auto pid : Pids()) {
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
            pid_data[pid] = {uid_user_map[an_id], Cmdline(pid)};
          }
        }
      }
    }
  }
  return pid_data;
}

int main() {
  auto uid_user_map = Uid_User_Map();
  cout << "Uids map has size :" << uid_user_map.size() << "\n\n";

  for (auto a_uid : uid_user_map) {
    cout << a_uid.first << " uid : user " << a_uid.second << "\n";
  }

  cout << "\n\n";

  for (auto pid_data : Pid_Data()) {
    cout << "pid " << pid_data.first << " : user " << pid_data.second[0] << " "
         << pid_data.second[1] << " "
         << "\n";
  }

  cout << "\n\n";

  cout << "Clock ticks per second: " << sysconf(_SC_CLK_TCK) << "Hz\n";

  cout << "\n\n";
}