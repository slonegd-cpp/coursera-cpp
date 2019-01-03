#include <string>
// #include <iostream>

bool IsPalindrom(std::string str)
{

   for (int i = 0; i < str.size() / 2 + 1; ++i) {
      if (str[i] != str[str.size()-i-1])
         return false;
   }
   return true;
}


// int main()
// {
//    std::string s;
//    std::cin >> s;
//    std::cout << IsPalindrom(s) << std::endl;
// }