#ifndef LANYI_STRING_H
#define LANYI_STRING_H
#include <iosfwd>
#include <cstring>

class String
{
  friend bool operator< ( const String& lhs, const String& rhs );
  friend bool operator< ( const char* lhs, const String& rhs );
  friend bool operator< ( const String& lhs, const char* rhs );

  friend std::ostream& operator<< (std::ostream& os, const String& str);

  friend String operator+ (const String& lhs, const String& rhs);
  friend String operator+ (const char* lhs, const String& rhs);
  friend String operator+ (char lhs, const String& rhs);
  friend String operator+ (const String& lhs, const char* rhs);
  friend String operator+ (const String& lhs, char rhs);

  public:
    String(){ init(""); }
    String(const String& str){ init(str.str_); }
    String(const char s[]){ init(s); }
    ~String(){ delete [] str_; }
    size_t size() const{ return length_; }
    const char* c_str ( ) const{ return str_; }
    const char& operator[] ( size_t pos ) const{ return str_[pos]; }
    char& operator[] ( size_t pos ){ return const_cast<char&>(static_cast<const String &>(*this)[pos]); }
    String& operator+= ( const String& str );
    String& operator+= ( const char* s ){ return (*this) += String(s); }
    String& operator+= ( char c );
    void clear();
    String& operator= ( const String& str );
    String& operator= ( const char* s ){ return (*this = String(s)); }
    String& operator= ( char c );
    void swap( String& str );

    static const char END_OF_STRING;

  private:
    void init(const char s[]);

    char *str_;
    size_t length_;
    size_t space_;
};

bool operator< ( const String& lhs, const String& rhs );
bool operator< ( const char* lhs, const String& rhs );
bool operator< ( const String& lhs, const char* rhs );

std::ostream& operator<< (std::ostream& os, const String& str);

String operator+ (const String& lhs, const String& rhs);
String operator+ (const char* lhs, const String& rhs);
String operator+ (char lhs, const String& rhs);
String operator+ (const String& lhs, const char* rhs);
String operator+ (const String& lhs, char rhs);

#endif // LANYI_STRING_H
