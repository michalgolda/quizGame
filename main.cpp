#include <iostream>
#include <unistd.h>
#include <string>
#include <nlohmann/json.hpp>
#include "question.cpp"


using json = nlohmann::json;
using namespace std;

int main()
{
	Question q;

	while(true)
	{
		system("clear");

		cout << "-- QUIZ GAME --" << endl;
		cout << endl;
		cout << "[1] Start" << endl;
		cout << "[0] Exit" << endl;
		
		int option;
		cin >> option;

		if(option == 1)
		{

			int points = 0;

			while(true)
			{

				json question = q.get_question();

				system("clear");

				string answer;

				string question_answer = question["answer"];
				string question_str = question["question"];
				string question_answerA = question["answerA"];
				string question_answerB = question["answerB"];
				string question_answerC = question["answerC"];

				cout << "Your points: " << points << endl;
				cout << endl;
				cout << "Question: " << question_str << endl;
				cout << "A. " << question_answerA << endl;
				cout << "B. " << question_answerB << endl;
				cout << "C. " << question_answerC << endl;
				cout << endl;
				cout << "Enter your answer: ";
				cin >> answer;

				if(answer == question_answer)
				{
					points = points + 1;
					cout << "Nice!" << endl;

					sleep(1);

					continue;
				} else {
					cout << "Ehhh.." << endl;

					sleep(1);

					continue;
				}
			}
		} else {
			break;
		}
	}

	return 0;
}