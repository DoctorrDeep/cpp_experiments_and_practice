#include <iostream>
#include <string>

class BankAccount {
public:
  BankAccount(int const &ac_n, std::string ow_n, double fu);

  // TODO: declare getters
  int AccNumber() const;
  std::string OwnerName() const;
  double Funds() const;

  // TODO: declare setters
  void OwnerName(std::string &owner_name);
  void Funds(double &funds);

private:
  // TODO: declare member variables
  int const acc_num;      // account number
  std::string owner_name; // owner name
  double funds{0.0f};      // available funds
};

BankAccount::BankAccount(int const &a_n, std::string o_n, double f)
    : acc_num(a_n), owner_name(o_n) {
  Funds(f);
}

// TODO: implement setters
void BankAccount::OwnerName(std::string &o_n) { owner_name = o_n; }
void BankAccount::Funds(double &f) {
  if (f >= 0)
    funds = f;
}

// TODO: implement getters
int BankAccount::AccNumber() const { return acc_num; }
std::string BankAccount::OwnerName() const { return owner_name; }
double BankAccount::Funds() const { return funds; }

int main() {
  // TODO: instantiate and output a bank account
  BankAccount myac(10000001, "Jon Doe", 10000003.45);

  std::cout << "\nAccount Information:\n";
  std::cout << "--------------------\n";
  std::cout << "Account ID: " << myac.AccNumber() << "\n";
  std::cout << "Account Holder:" << myac.OwnerName() << "\n";
  std::cout << "Account Balance: " << myac.Funds() << "\n\n";
}