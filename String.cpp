#include <iostream>
#include <cstring>
#include <algorithm>
#include "String.h"
using namespace std;

const char String::END_OF_STRING = '\0';

String& String::operator+= ( const String& str ){
  if( length_ + str.length_ + 1 <= space_ ){
    length_ = length_ + str.length_;
    strcat( str_, str.str_ );
    return *this;
  }
  else return (*this = *this + str);
}

String& String::operator+= ( char c ){
  char temp[] = {c, END_OF_STRING};
  return (*this) += String(temp);
}

String& String::operator= ( const String& str ){
  String temp(str);
  swap(temp);
  return *this;
}

String& String::operator= ( char c ){
  char temp[] = {c, END_OF_STRING};
  return (*this = String(temp));
}

void String::swap( String& str ){
  std::swap( length_, str.length_ );
  std::swap( space_, str.space_ );
  std::swap( str_, str.str_ );
}

void String::init(const char s[]){
  length_ = strlen(s);
  space_ = length_+1;
  str_ = new char[space_];
  strcpy( str_, s );
}

bool operator< ( const String& lhs, const String& rhs ){
  return (strcmp(lhs.str_, rhs.str_) < 0);
}

bool operator< ( const char* lhs, const String& rhs ){
  return (strcmp(lhs, rhs.str_) < 0);
}

bool operator< ( const String& lhs, const char* rhs ){
  return (strcmp(lhs.str_, rhs) < 0);
}

std::ostream& operator<< (std::ostream& os, const String& str){
  return os << str.str_;
}

String operator+ (const String& lhs, const String& rhs){
  char *temp = new char[lhs.length_ + rhs.length_ + 1];
  strcpy( temp, lhs.str_ );
  strcat( temp, rhs.str_ );

  String return_str( temp );
  delete [] temp;
  return return_str;
}

String operator+ (const char* lhs, const String& rhs){
  return String(lhs) + rhs;
}

String operator+ (char lhs, const String& rhs){
  char temp_str[] = {lhs, String::END_OF_STRING};
  return String(temp_str) + rhs;
}

String operator+ (const String& lhs, const char* rhs){
  return lhs + String(rhs);
}

String operator+ (const String& lhs, char rhs){
  char temp_str[] = {rhs, String::END_OF_STRING};
  return lhs + String(temp_str);
}
