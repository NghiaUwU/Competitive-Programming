#include <iostream>       // std::cout
#include <system_error>   // std::error_condition, std::errc, std::generic_category
#include <cerrno>         // EEXIST

int main()
{
  // two ways of creating the same error_condition:
  std::error_condition foo (std::errc::file_exists);
  std::error_condition bar (EEXIST, std::generic_category() );

  if (foo == bar) std::cout << foo.message();

  return 0;
}