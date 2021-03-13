class NoCopyClass1 {
private: // prevent copying by declaring but not defining a private copy constructor and assignment operator
  NoCopyClass1(const NoCopyClass1 &);
  NoCopyClass1 &operator=(const NoCopyClass1 &);

public:
  NoCopyClass1(){};
};

class NoCopyClass2 {
public: // both methods are now public and the delete operator has been assigned
  NoCopyClass2() {}
  NoCopyClass2(const NoCopyClass2 &) = delete;
  NoCopyClass2 &operator=(const NoCopyClass2 &) = delete;
};

int main() {
  NoCopyClass1 original1;
  NoCopyClass1 copy1a(original1);  // copy c’tor: fails compilation because it is private
  NoCopyClass1 copy1b = original1; // assigment operator: fails compilation because it is private

  NoCopyClass2 original2;
  NoCopyClass2 copy2a(original2);  // copy c’tor: cannot be called since its a deleted function
  NoCopyClass2 copy2b = original2; // assigment operator: cannot be called since its a deleted function

  return 0;
}