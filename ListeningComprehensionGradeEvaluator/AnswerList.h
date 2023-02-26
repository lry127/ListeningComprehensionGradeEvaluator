#pragma once

#include <array>
#include <string>
#include <set>
#include <memory>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#ifdef _MSC_VER // windows for colored output
#include <Windows.h>
#endif

class AnswerList
{
public:
    AnswerList(const std::string& sec_ab, const std::string& sec_c)
    {
        if (sec_ab.size() < num_section_a_and_b || sec_c.size() < num_section_c)
        {
            std::cerr << "invalid input size.\n";
            std::exit(-1);
        }

        std::copy_n(sec_ab.cbegin(), num_section_a_and_b, sec_ab_answers.begin());
        std::copy_n(sec_c.cbegin(), num_section_c, sec_c_answers.begin());
    }

    static double compare(const AnswerList& a1, const AnswerList& a2, std::shared_ptr<std::set<unsigned>> diff_ptr);
    static void print_diff(const AnswerList& a1, const AnswerList& a2, std::shared_ptr<std::set<unsigned>> diff_ptr);

    static double get_total_scores() { return total_scores; }

private:
    inline static const unsigned num_section_a_and_b = 15;
    inline static const unsigned num_section_c = 10;
    inline static const double scores_section_a_and_b = 7.1;
    inline static const double scores_section_c = 14.2;

    inline static const double total_scores = num_section_a_and_b * scores_section_a_and_b + num_section_c * scores_section_c;

    std::array<char, num_section_a_and_b> sec_ab_answers;
    std::array<char, num_section_c> sec_c_answers;
};
