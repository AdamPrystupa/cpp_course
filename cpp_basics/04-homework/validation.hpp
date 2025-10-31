#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <string>

enum class ErrorCode {
  Ok,
  PasswordNeedsAtLeastNineCharacters,
  PasswordNeedsAtLeastOneNumber,
  PasswordNeedsAtLeastOneSpecialCharacter,
  PasswordNeedsAtLeastOneUppercaseLetter,
  PasswordsDoNotMatch
};

std::string getErrorMessage(const ErrorCode &);
bool doPasswordsMatch(const std::string &, const std::string &);
ErrorCode checkPasswordRules(const std::string &);
ErrorCode checkPassword(const std::string &, const std::string &);

#endif