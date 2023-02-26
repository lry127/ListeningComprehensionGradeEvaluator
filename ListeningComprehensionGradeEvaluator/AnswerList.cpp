#include "AnswerList.h"


double AnswerList::compare(const AnswerList& a1, const AnswerList& a2, std::shared_ptr<std::set<unsigned>> diff_ptr)
{
	unsigned sec_ab_correct = 0;
	unsigned sec_c_correct = 0;
	for (int i = 0; i < num_section_a_and_b; ++i)
	{
		if (a1.sec_ab_answers[i] == a2.sec_ab_answers[i])
			sec_ab_correct++;
		else if (diff_ptr)
			diff_ptr->insert(i);
	}

	for (int i = 0; i < num_section_c; ++i)
	{
		if (a1.sec_c_answers[i] == a2.sec_c_answers[i])
			sec_c_correct++;
		else if (diff_ptr)
			diff_ptr->insert(i + num_section_a_and_b);
	}

	return sec_ab_correct * scores_section_a_and_b +
		sec_c_correct * scores_section_c;

}

void AnswerList::print_diff(const AnswerList& a1, const AnswerList& a2, std::shared_ptr<std::set<unsigned>> diff_ptr)
{
	if (!diff_ptr)
	{
		std::cerr << "Analysis is OFF.\n";
		return;
	}

	std::cout << "Details:\n";
	std::cout << "\t----------\t\n";
#ifdef _MSC_VER

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#endif
	const auto set_color = [&](unsigned no = -1) {

#ifdef _MSC_VER
		if (no == 0)
		{
			// red 
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		}
		else if (no == 1)
		{
			// green
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		}
		else
		{
			// black
			SetConsoleTextAttribute(hConsole, 7);
		}
#endif // _MSC_VER
	};



	const auto print_each = [&](unsigned num) {
		std::cout << num + 1 << ". ";
		if (num < num_section_a_and_b)
		{
			set_color(1);
			std::cout << a2.sec_ab_answers[num];
			set_color();
			std::cout << ". Actual: ";
			set_color(0);
			std::cout << a1.sec_ab_answers[num];
			set_color();
			std::cout << " (-" << scores_section_a_and_b << " scores.)\n";
		}
			
		else
		{
			set_color(1);
			std::cout << a2.sec_c_answers[num - num_section_a_and_b];
			set_color();
			std::cout << ". Actual: ";
			set_color(0);
			std::cout << a1.sec_c_answers[num - num_section_a_and_b];
			set_color();
			std::cout << " (-" << scores_section_c << " scores.)\n";
		
		}
	};

	for (unsigned num : *diff_ptr)
			print_each(num);

	std::cout << "\t----------\t\n";
}