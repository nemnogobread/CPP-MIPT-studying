#include <iostream>
#include <string>
#include <cmath>

unsigned long get_really_any_hexadecimal();
unsigned long conv_16_to_10(int N, std::string s);

int main() 
{
  std::cout << get_really_any_hexadecimal() << std::endl;
  return 0;
}

unsigned long get_really_any_hexadecimal() 
{
  std::string input, result_16 = "";
  std::cout << "Please, input data: ";
  std::cin >> input;
  
  for ( int i = 0 ; i < input.length() ; i++ )
    {
      if (( '0' <= input[i] && input[i] <= '9') || ('A' <= input[i] && input[i] <= 'F' ))
        result_16.push_back(input[i]) ;
      else if ('a' <= input[i] && input[i] <= 'f')
        result_16.push_back(toupper(input[i])) ;
    }

  std::cout << "correct number in 16: " << result_16 << std::endl;
  
  return conv_16_to_10(result_16.length(), result_16);
}

unsigned long conv_16_to_10(int N, std::string s)
{
  unsigned long result_10 = 0 ;
  for (int i = 0 ; i < N ; i++)
    {
      if (s[i] < 'A')
        result_10 += (int)(s[i]-'0') * pow(16, N-i-1) ;
      else
        result_10 += (10 + (int)(s[i] - 'A')) * pow(16, N-i-1) ;
    }

  std::cout << "result in 10: " ;
  return result_10;
}