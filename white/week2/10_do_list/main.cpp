#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iterator>

using Do_list = std::vector<std::string>;

std::ostream& operator<< (std::ostream& s, const Do_list& list)
{
   s << list.size() << ' ';
   for (auto& str : list)
      s << str << ' ';
   s << std::endl;
   return s;
}

Do_list& operator<< (Do_list& to, const Do_list& from)
{
   to.insert (std::end(to), std::begin(from), std::end(from));
   return to;
}

template<class T>
T get (std::istream& s)
{
   return *std::istream_iterator<T>(s);
}



int main()
{
   constexpr std::array<int,12> days_in_mouth { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int current {0};
   std::vector<Do_list> mounth;
   mounth.resize (days_in_mouth[current]);

   auto action_count = get<int>(std::cin);
   while (action_count--) {
      auto command = get<std::string>(std::cin);

      if (command == "ADD") {
         auto day = get<int>(std::cin) - 1;
         mounth[day].push_back (get<std::string>(std::cin));
         continue;
      }

      if (command == "DUMP") {
         auto day = get<int>(std::cin);
         std::cout << mounth[day - 1];
         continue;
      }

      if (command == "NEXT") {
         int last = days_in_mouth[current];
         current++;
         if (current == 12) current = 0;
         if (last <= days_in_mouth[current]) {
            mounth.resize (days_in_mouth[current]);
         } else {
            for (; last != days_in_mouth[current]; --last)
               mounth[days_in_mouth[current] - 1] << mounth[last - 1];
            mounth.resize (days_in_mouth[current]);
         }
         continue;
      }

   } // while (action_count--) {
}
