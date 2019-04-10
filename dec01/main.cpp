#include "../common.hpp"

namespace
{
int part_one(const std::vector<int> &vec3)
{
    return std::accumulate(vec3.cbegin(), vec3.cend(), 0);
}

int part_two(const std::vector<int> &vec)
{
    std::set<int> freqSet;
    int total = 0;

    while (true)
    {
        for (int i : vec)
        {
            total += i;
            if (auto [iter, inserted] = freqSet.insert(total); !inserted)
            {
                return total;
            }
        }
    }
    return 0;
}

} // namespace

int main(int argc, char **argv)
{
    typedef std::istream_iterator<int> iter_t;
    std::ifstream file("input.txt");
    std::vector<int> const vec((iter_t(file)), iter_t());
    std::cout << "Part 1 result is " << part_one(vec) << "\n";
    std::cout << "Part 2 result is " << part_two(vec) << "\n";
}