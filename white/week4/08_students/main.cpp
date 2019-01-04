#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <vector>

struct Student {
   std::string name;
   std::string last_name;
   int day;
   int month;
   int year;
};



template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}

int main()
{
   std::vector<Student> students;

   auto count = get<int>(std::cin);
   while (count--)
      students.push_back ({
         get<std::string>(std::cin),
         get<std::string>(std::cin),
         get<int>(std::cin),
         get<int>(std::cin),
         get<int>(std::cin),
      });
   
   count = get<int>(std::cin);
   while (count--) {
      auto command = get<std::string>(std::cin);
      auto n = get<int>(std::cin);
      --n;

      if (n >= students.size()) {
         std::cout << "bad request" << std::endl;
         continue;
      }

      if (command == "name") {
         std::cout << students[n].name << ' ' << students[n].last_name << std::endl;
         continue;
      }

      if (command == "date") {
         std::cout << students[n].day << '.' << students[n].month << '.' << students[n].year << std::endl;
         continue;
      }

      std::cout << "bad request" << std::endl;
   }
}
