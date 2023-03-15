#include <ksum.hpp>
#include <boost/program_options.hpp>

#include <algorithm>
#include <iostream>
#include <ranges>

int main(int argc, char **argv)
{
    boost::program_options::options_description description{"Options"};
    description.add_options() (
            "help,h",
            "show help menu"
        )(
            "list,l",
            boost::program_options::value<std::vector<int>>(),
            "list of comma-separated numbers"
        )(
            "sum,k",
            boost::program_options::value<int>(),
            "summation that would be looked up for"
        );

    boost::program_options::variables_map arguments;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, description), arguments);
    boost::program_options::notify(arguments);

    if (arguments.count("help"))
    {
        std::cerr << argv[0] << " -l <numbers> -k <sum>\n";
        std::cerr << description << std::endl;
        return 1;
    }

    std::vector<int> numbers{};
    int k{};

    if (arguments.count("list"))
    {
        std::ranges::copy(arguments["list"].as<std::vector<int>>(), std::back_insert_iterator(numbers));
        std::ranges::copy(numbers, std::ostream_iterator<int>(std::cerr, " "));
    }
    else
    {
        std::cerr << description << std::endl;
        return 1;
    }

    if (arguments.count("sum"))
    {
        k = arguments["sum"].as<int>();
    }
    else
    {
        std::cerr << description << std::endl;
        return 1;
    }

    std::cout << std::boolalpha << ksum(numbers, k) << std::endl;
}
