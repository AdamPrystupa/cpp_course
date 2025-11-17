/*
Zadanie 2 - advanced-calculator

Napisz program advanced_calculator. Ma on posiadać pętle główną, która będzie
przyjmować dane od użytkownika i wyświetlać wynik, np. dla 5 % 3 ma zwrócić
wynik 2. Wszystkie komendy kalkulatora powinny być przechowywane w mapie, która
jako klucz przechowuje znak char odwołujący się do konkretnej komendy (np. + ->
dodaj , % -> modulo), a jako wartości std::function<> będące wraperem na
wyrażenia lambda dokonujące określonej kalkulacji.

Program powinien także zwracać odpowiedni kod błędu, jeżeli użytkownik poda złe
dane. Np. dzielenie przez 0 lub spróbuje dodać ala + 5.

    Input: 5 + 5 -> operacja dodawania dwóch liczb 5 i 5 -> output: 10.
    Input: 5 ^ 2 -> operacje potęgowania -> output 25.
    Input: 125 $ 3 -> operacja pierwiastka (sqrt za długie), pierwiastek
sześcienny z 125 -> output: 5.

Funkcja, która będzie testowana

ErrorCode process(std::string input, double* out)

    Funkcja ta powinna przyjmować dane od użytkownika oraz dokonywać
odpowiedniej kalkulacji Jeżeli dane są poprawne, ma zwrócić ErrorCode:Ok, a w
zmiennej out ma zapisać wynik Jeżeli wystąpi któryś z błędów, funkcja ma go
zwrócić, a w out ma nic nie zapisywać
*/

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

enum class ErrorCode {
  Ok,
  BadCharacter,            // znak inny niż liczba
  BadFormat,               // zły format komendy np.+ 5 4,  powinno być 4 + 5
  DivideBy0,               // dzielenie przez 0
  SqrtOfNegativeNumber,    // pierwiastek z liczby ujemnej
  ModuleOfNonIntegerValue, // próba obliczenia % na liczbie niecałkowitej
};

struct Calculator {
  std::map<char, std::function<ErrorCode(double, double, double *)>> commands;

  Calculator() {
    commands['+'] = [](double a, double b, double *out) {
      *out = a + b;
      return ErrorCode::Ok;
    };
    commands['*'] = [](double a, double b, double *out) {
      *out = a * b;
      return ErrorCode::Ok;
    };
    commands['/'] = [](double a, double b, double *out) {
      if (b == 0) {
        return ErrorCode::DivideBy0;
      }
      *out = a / b;
      return ErrorCode::Ok;
    };
    commands['-'] = [](double a, double b, double *out) {
      *out = a - b;
      return ErrorCode::Ok;
    };
    commands['%'] = [](double a, double b, double *out) {
      if (std::floor(a) != a || std::floor(b) != b) {
        return ErrorCode::ModuleOfNonIntegerValue;
      }
      if (b == 0) {
        return ErrorCode::DivideBy0;
      }
      *out = std::fmod(a, b);
      return ErrorCode::Ok;
    };
    commands['!'] = [](double a, double b, double *out) {
      (void)b;
      *out = std::tgamma(a + 1);
      return ErrorCode::Ok;
    };
    commands['^'] = [](double a, double b, double *out) {
      *out = std::pow(a, b);
      return ErrorCode::Ok;
    };
    commands['$'] = [](double a, double b, double *out) {
      if (a < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
      }
      *out = std::pow(a, 1.0 / b);
      return ErrorCode::Ok;
    };
  }

  ErrorCode process(std::string input, double *out);
};

void printError(const ErrorCode &error) {
  switch (error) {
  case ErrorCode::BadCharacter:
    std::cout << "Error: Bad characters!\n";
    break;
  case ErrorCode::BadFormat:
    std::cout << "Error: Bad format!\n";
    break;
  case ErrorCode::DivideBy0:
    std::cout << "Error: Divide by 0!\n";
    break;
  case ErrorCode::SqrtOfNegativeNumber:
    std::cout << "Error: Sqrt of negative number!\n";
    break;
  case ErrorCode::ModuleOfNonIntegerValue:
    std::cout << "Error: Module of non integer value!\n";
    break;
  default:
    break;
  }
}

int main() {

  double result = 0;
  std::string line = "";
  std::getline(std::cin, line);
  Calculator calc;
  auto error = calc.process(line, &result);
  if (error != ErrorCode::Ok) {
    printError(error);
  } else {
    std::cout << result;
  }

  return 0;
}

ErrorCode Calculator::process(std::string input, double *out) {
  std::stringstream ss(input);
  double arg1 = 0.0;
  double arg2 = 0.0;
  char op = 0;

  if (!(ss >> arg1)) {
    return ErrorCode::BadCharacter;
  }

  if (!(ss >> op)) {
    return ErrorCode::BadFormat;
  }

  auto it = commands.find(op);
  if (it == commands.end()) {
    return ErrorCode::BadFormat;
  }

  bool isFactorial = (op == '!');

  if (isFactorial) {
    std::string rest;
    if (ss >> rest) {
      return ErrorCode::BadFormat;
    }
    return it->second(arg1, 0.0, out);

  } else {
    if (ss >> arg2) {
      std::string reszta;
      if (ss >> reszta) {
        return ErrorCode::BadFormat;
      }
      return it->second(arg1, arg2, out);

    } else {
      if (ss.eof()) {
        return ErrorCode::BadFormat;
      } else {
        return ErrorCode::BadCharacter;
      }
    }
  }
};
