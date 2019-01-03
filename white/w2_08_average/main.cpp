#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


int main()
{
   int n;
   std::cin >> n;
   std::vector<int> in;
   in.reserve(n);
   std::copy_n (std::istream_iterator<int>(std::cin), n, std::back_inserter(in));

   int sum = 0;
   for (auto n : in)
      sum += n;
   sum /= in.size();

   std::vector<int> out;
   for (int i = 0; i < in.size(); ++i)
      if (in[i] > sum)
         out.push_back(i);

   std::cout << out.size() << std::endl;
   for (auto n : out)
      std::cout << n << ' ';
   std::cout << std::endl;
   
}