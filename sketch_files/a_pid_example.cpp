#include <iostream>
#include <memory>

class theError {
public:
  theError(const double &error, const double &s_error, const double &u_e_limit,
           const double &l_e_limit) {
    _error = error;
    _smallest_error_sq = s_error * s_error;
    _upper_limit = u_e_limit;
    _lower_limit = l_e_limit;
  }

  double current_e() { return _error; }
  int current_step() { return _step_count; }

  // Synthetic change to the error after correction has been computed
  void execute(double &correction) {
    _step_count += 1;
    (_error * _error > _smallest_error_sq &&
     _upper_limit > _error > _lower_limit)
        ? _error -= correction
        : _error = 0;
  }

  // Print number of steps till now and the current error
  void print_error() {
    std::cout << "At step #" << _step_count << ", error is = " << _error
              << "\n";
  }

private:
  double _error, _smallest_error_sq, _upper_limit, _lower_limit;
  int _step_count = 0;
};

int main() {

  // delta of time between 2 readings i.e. frequency of signal(reading of e)
  double delta_t = 1/100;

  // Smallest relevant error value
  double smallest_error = 0.001;

  // Biggest relevant error value
  double biggest_error = 2000;

  // Error initialization
  std::unique_ptr<theError> error(
      new theError(1000.0, smallest_error, biggest_error, -1 * biggest_error));

  double prev_e = 0;
  double tot_e = 0;
  int Kp = 1;
  double Ki = 50000; // doesnt do muchin the synthetic response/corrections
  double Kd = 0.001;
  double correction = 0;

  while (error->current_e() != 0) {
    error->print_error();
    double e = error->current_e();
    tot_e += e * delta_t;
    correction = Kp * e + Kd * (prev_e - e) + Ki * tot_e;
    error->execute(correction);
    prev_e = e;

    // if (error.current_step() > 30){
    //   break;
    // }
  }

  error->print_error();

  return 0;
}

// OUTPUT

// At step #0, error is = 1000
// At step #1, error is = 1
// At step #2, error is = -0.999
// At step #3, error is = -0.001999
// At step #4, error is = 0.000997001
// At step #5, error is = 0