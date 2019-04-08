#include "../common.hpp"

namespace
{
int part_one(const std::vector<int> &vec3)
{
    return std::accumulate(vec3.cbegin(), vec3.cend(), 0);
}
} // namespace

int main(int argc, char **argv)
{
    typedef std::istream_iterator<int> iter_t;
    std::ifstream file("input.txt");
    const std::vector<int> vec((iter_t(file)), iter_t());
    std::cout << "Part 1 result is " << part_one(vec) << "\n";
}