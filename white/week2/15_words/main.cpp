#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   std::set<std::string> words;

   auto count = get<int>(std::cin); 
   while (count--)
      words.insert (get<std::string>(std::cin));

   std::cout << words.size() << std::endl;
}