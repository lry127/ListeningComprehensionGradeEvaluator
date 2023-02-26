// ListeningComprehensionGradeEvaluator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <sstream>

#include "AnswerList.h"

int main(int argc, char** argv)
{
	std::ifstream data_file;
	if (argc < 2)
	{
		// no data file
		data_file.open("data.txt");
	}
	else
	{
		data_file.open(argv[1]);
	}
	

	if (!data_file.is_open())
	{
		std::cerr << "can't open file: " << argv[1] << std::endl;
		std::exit(-1);
	}

	std::string real_1, real_2, real_3, real_4, real_5;
	std::string correct_1, correct_2, correct_3, correct_4, correct_5;

	bool enable_detail = false;
	data_file >> real_1 >> real_2 >> real_3 >> real_4 >> real_5;
	data_file >> correct_1 >> correct_2 >> correct_3 >> correct_4 >> correct_5;
	data_file >> enable_detail;
	
	std::string real1(real_1 + real_2 + real_3);
	std::string real2(real_4 + real_5);
	
	std::string correct1(correct_1 + correct_2 + correct_3);
	std::string correct2(correct_4 + correct_5);

	AnswerList als(real1, real2);
	AnswerList correct(correct1, correct2);
	
	std::shared_ptr<std::set<unsigned>> diff_ptr(enable_detail ? new std::set<unsigned> : nullptr);

	double actual_scores = AnswerList::compare(als, correct, diff_ptr);

#ifdef _MSC_VER
	void* console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _MSC_VER

	std::cout << "You got ";

#ifdef _MSC_VER
	SetConsoleTextAttribute(console, FOREGROUND_RED);
#endif

	std::cout << actual_scores;

#ifdef _MSC_VER
	SetConsoleTextAttribute(console, 7);
#endif

	std::cout << " (" << std::to_string(actual_scores / AnswerList::get_total_scores() * 100).substr(0,4)  << "%)" << " scores." << std::endl;

	AnswerList::print_diff(als, correct, diff_ptr);

#ifdef _MSC_VER
	std::system("pause"); // wait for the output on Windows os
#endif 

	return 0;

}
