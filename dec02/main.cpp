#include "../common.hpp"

namespace
{

struct repeat_info
{
    bool has_two = false;
    bool has_three = false;
};

repeat_info count_repeating(const std::string &str)
{
    std::array<int, 26> occurances{};
    for (const char c : str)
    {
        ++occurances[c - 'a'];
    }

    repeat_info r{};
    for (const int i : occurances)
    {
        if (i == 2)
        {
            r.has_two = true;
        }
        else if (i == 3)
        {
            r.has_three = true;
        }
    }
    return r;
}

} // namespace

int main(int argc, char **argv)
{
    typedef std::istream_iterator<std::string> iter_t;
    std::ifstream file("input.txt");
    const auto input = std::vector<std::string>(iter_t(file), iter_t());

    std::vector<repeat_info> counter(input.size());
    std::transform(input.begin(), input.end(), counter.begin(), count_repeating);
    std::cout << "isize:" << input.size() << "\ncsize:" << counter.size() << "\n";

    const auto two_count = std::count_if(counter.cbegin(), counter.cend(), [](const repeat_info info) { return info.has_two; });
    const auto three_count = std::count_if(counter.cbegin(), counter.cend(), [](const repeat_info info) { return info.has_three; });
    std::cout << "Part 1 result is " << two_count << "," << three_count << "," << two_count * three_count << "\n";
    // std::cout << "Part 2 result is " << part_two(vec) << "\n";
}