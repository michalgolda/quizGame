#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <nlohmann/json.hpp>
#include "question.h"

using json = nlohmann::json;

json Question::get_question()
{
	std::ifstream f("questions.json");

	json questions;
	f >> questions;

	srand(time(0));

	int questionsCount = questions.size();
	int randomQuestionIndex = rand() % questionsCount;

	json question = questions[randomQuestionIndex];

	return question;
}