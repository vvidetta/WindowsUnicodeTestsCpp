// UnicodeTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include "io.h"
#include "fcntl.h"
#include <codecvt>
#include <fstream>

auto const mb_alpha = u8"\u03B1"; // Greek Small Letter Alpha
auto const wide_alpha = L"\u03B1";
auto const mb_path = std::filesystem::path{ mb_alpha };
auto const wide_path = std::filesystem::path{ wide_alpha };

void stream_mb_alpha()
{
    // This doesn't work...
    std::cout << mb_alpha;
}

void stream_wide_alpha()
{
    std::cout << "The alpha is: ";
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << wide_alpha;
    std::cout << "Hello";
    _setmode(_fileno(stdout), _O_TEXT); // _O_U16TEXT);
    std::cout << " done!";
}

void print_mb_alpha()
{
    // This doesn't work...
    printf(mb_alpha);
}

void print_wide_alpha()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(wide_alpha);
}

void write_wide_ascii_to_file()
{
    //_setmode(_fileno(stdout), _O_U16TEXT);
    auto fs = std::wofstream{ wide_alpha };
    fs << L"Hello world!" << std::endl;
}

void write_wide_alpha_to_file()
{
/*    auto const codecvt = new std::codecvt<wchar_t, char, mbstate_t>();

    auto mbstate = mbstate_t{};
    auto const mb_alpha_obj = std::string{ mb_alpha };
    auto from_next = mb_alpha_obj.c_str();
    auto wide_alpha_buf = std::vector<wchar_t>(16);
    auto to_next = wide_alpha_buf.data();
    auto result = codecvt->in(
        mbstate,
        mb_alpha_obj.c_str(),
        mb_alpha_obj.c_str() + mb_alpha_obj.size() + 1,
        from_next,
        wide_alpha_buf.data(),
        wide_alpha_buf.data() + wide_alpha_buf.size(),
        to_next
    );

    auto wide_alpha_obj = std::wstring(wide_alpha_buf.data());

    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << wide_alpha_obj << std::endl; */

    /* auto locale = std::locale{ std::locale(), codecvt };
    auto fs = std::wofstream{ wide_alpha };
    fs.imbue(locale);
    fs << wide_alpha << std::endl; */
}

int main()
{
    //write_wide_alpha_to_file();
    stream_wide_alpha();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
