#include <cassert>
#include <stdexcept>
#include <string>

// TODO: Define "Student" class
class Student {
public:
  // constructor
  Student(std::string nm, int grd, float gpa);

  // accessors
  std::string Name() const { return name_; };
  int Grade() const { return grade_; };
  float Gpa() const { return gpa_; };

  // mutators
  void Name(std::string nm) { name_ = nm; };
  void Grade(int &grd);
  void Gpa(float gpa);

private:
  std::string name_; // name
  int grade_;        // grade
  float gpa_;        // GPA
};

Student::Student(std::string nm, int grd, float gpa) {
  Name(nm);
  Grade(grd);
  Gpa(gpa);
};

void Student::Gpa(float g) {
  if (g >= 0.0f && g <= 4.0f)
    gpa_ = g;
  else
    throw std::invalid_argument("GPA should be a float from 0 to 4");
}

void Student::Grade(int &g) {
  if (g > 0 && g <= 12)
    grade_ = g;
  else
    throw std::invalid_argument("Grade should be an int from 1 to 12");
}

// TODO: Test
int main() {
  Student a_student("John Doe", 9, 3.2);

  // Test 1
  assert(a_student.Name() == "John Doe");
  assert(a_student.Grade() == 9);
  assert(a_student.Gpa() == 3.2f);
  
  // Test 2
  bool an_exception = false;
  try{
    a_student.Gpa(31.2f);
  } catch(...){
    an_exception = true;
  };
  assert(an_exception);

  // Test 3
  an_exception = false;
  try{
    Student b_student("John Doe", 9, 10);
  } catch(...){
    an_exception = true;
  };
  assert(an_exception);

  // Test 4
  an_exception = false;
  try{
    Student b_student("John Doe", 0, 3.2);
  } catch(...){
    an_exception = true;
  };
  assert(an_exception);
}