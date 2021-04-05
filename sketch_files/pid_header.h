#ifndef PID_HEADER
#define PID_HEADER
#include <iostream>

class theError {
public:
  theError(double &&error, double &s_error, double &u_e_limit,
           double &&l_e_limit)
      : _error(error), _upper_limit(u_e_limit), _lower_limit(l_e_limit) {
    _smallest_error_sq = s_error * s_error;
    _step_count = 0;
  }

  double current_e() { return _error; }
  int current_step() { return _step_count; }

  void execute(double &correction);

  // Print number of steps till now and the current error
  void print_error() {
    std::cout << "At step #" << _step_count << ", error is = " << _error
              << "\n";
  }

private:
  double _error, _smallest_error_sq, _upper_limit, _lower_limit;
  int _step_count;
};

#endif
