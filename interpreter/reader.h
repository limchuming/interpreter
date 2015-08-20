#ifndef READER
#define READER

#include <iostream>
#include <sstream>

template <typename T>
class Reader{
public:
  Reader();
  std::string read_identifier();
  T factor();
  T term();
  T expression();
private:
  const char *allowed_idenchar;
  char current_ch;
  std::istream &is;
};

Reader::Reader():allowed_idenchar("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"){}

std::string Reader::read_identifier(){
  if(isspace(current_ch)){
    // skip empty spaces
    is >> current_ch;
  }
  
  if(isalpha(current_ch)){
    // first letter has to be a letter of the alphabet
    // thereafter it needs to be in the allowed_idenchar list
    while(isalnum(current_ch)){
      // get letter by letter and stop when the char stops being in allowed_idenchar
      
      current_ch = is.get();
      
    }
  }
  
  
  
  
}



template <typename T>
T Reader<T>::expression(){
  factor
  
  std::cin >> current_ch;
}


#endif


