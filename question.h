#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Question{
public:
	json get_question();
};