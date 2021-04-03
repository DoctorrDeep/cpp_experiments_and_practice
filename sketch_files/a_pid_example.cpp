#include <iostream>

class theError {
public:
  theError(double &&error, const double &s_error) {
    _error = error;
    _smallest_error_sq = s_error * s_error;
  }

  double current_e() { return _error; }
  int current_step() { return _step_count; }

  void execute(double &correction) {
    _step_count += 1;
    if (_error == 0) {
      return;
    }
    if (_error * _error < _smallest_error_sq) {
      _error = 0;
      return;
    }
    _error -= correction;
  }

  void print_error() {
    std::cout << "At step #" << _step_count << ", error is = " << _error
              << "\n";
  }

private:
  double _error, _smallest_error_sq;
  int _step_count = 0;
};

int main() {

  // delta of time between 2 readings i.e. frequency of signal(reading of e)
  double delta_t = 1 / 100;
  // Smallest relevant error value
  double smallest_error = 0.001;
  // Error
  theError error(1000.0, smallest_error);

  double prev_e = 0;
  double tot_e = 0;
  int Kp = 1;
  double Ki = 0.6;
  double Kd = 0.001;
  double correction = 0;

  while (error.current_e() != 0) {
    error.print_error();
    double e = error.current_e();
    tot_e += e * delta_t;
    correction = Kp * e + Kd * (prev_e - e) + Ki * tot_e;
    error.execute(correction);
    prev_e = e;

    // if (error.current_step() > 30){
    //   break;
    // }
  }

  return 0;
}

// OUTPUT
// At step #0, error is = 1000
// At step #1, error is = 1
// At step #2, error is = -0.999
// At step #3, error is = -0.001999
// At step #4, error is = 0.000997001