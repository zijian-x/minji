#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <regex>

#include "../core/deck.h"
#include "../core/card.h"
#include "parse_error.h"
#include "../core/answers/multi_answer.h"
#include "../core/answers/plain_answer.h"
#include "../core/answers/answer_factory.h"

namespace io
{
    std::shared_ptr<minji::deck> parse_markdown(const std::string_view fname,
	    const std::string& deck_name);
}