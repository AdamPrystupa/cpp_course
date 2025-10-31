#include <iostream>
#include <memory>

// TODO: Implement foo()
// It should take shared_ptr to int and assign value 20 to the pointed int.
// It should also display the value of this int and the number of how many
// pointers are pointing to it - use `use_count()`. Display the same information
// in main() before and after calling foo()
void foo(std::shared_ptr<int> num) {
  *num = 20;
  std::cout << "in fun foo() value == " << *num << "\n";
  std::cout << "in fun foo() use_count == " << num.use_count() << "\n";
}

int main() {
  std::shared_ptr<int> number = std::make_shared<int>(10);
  // display the value under number pointer and use_count() of it
  std::cout << "before fun foo() value == " << *number << "\n";
  std::cout << "before fun foo() use_count == " << number.use_count() << "\n";
  foo(number);
  // display the value under number pointer and use_count() of it
  std::cout << "after fun foo() value == " << *number << "\n";
  std::cout << "after fun foo() use_count == " << number.use_count() << "\n";
  return 0;
}