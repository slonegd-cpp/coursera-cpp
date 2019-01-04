#include <fstream>
#include <iostream>

int main()
{
   std::ifstream file ("input.txt");
   std::ofstream out ("output.txt");
   std::string line;
   while (std::getline(file,line))
      out << line << std::endl;
}