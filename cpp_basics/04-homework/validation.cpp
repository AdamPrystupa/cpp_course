#include "validation.hpp"

std::string getErrorMessage(const ErrorCode &code) {
  switch (code) {
  case ErrorCode::Ok:
    return "Ok";
  case ErrorCode::PasswordNeedsAtLeastNineCharacters:
    return "PasswordNeedsAtLeastNineCharacters";
  case ErrorCode::PasswordNeedsAtLeastOneNumber:
    return "PasswordNeedsAtLeastOneNumber";
  case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
    return "PasswordNeedsAtLeastOneSpecialCharacter";
  case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
    return "PasswordNeedsAtLeastOneUppercaseLetter";
  case ErrorCode::PasswordsDoNotMatch:
    return "PasswordsDoNotMatch";
  default:
    return "Unknown error";
  }
}

bool doPasswordsMatch(const std::string &pass1, const std::string &pass2) {
  return pass1 == pass2;
}

ErrorCode checkPasswordRules(const std::string &pass) {
  if (pass.length() < 9)
    return ErrorCode::PasswordNeedsAtLeastNineCharacters;
  else if (std::none_of(pass.begin(), pass.end(),
                        [](char c) { return std::isdigit(c); }))
    return ErrorCode::PasswordNeedsAtLeastOneNumber;
  else if (std::none_of(pass.begin(), pass.end(),
                        [](char c) { return std::ispunct(c); }))
    return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
  else if (std::none_of(pass.begin(), pass.end(),
                        [](char c) { return std::isupper(c); }))
    return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
  else
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string &pass1, const std::string &pass2) {
  if (!doPasswordsMatch(pass1, pass2))
    return ErrorCode::PasswordsDoNotMatch;
  return checkPasswordRules(pass1);
}
