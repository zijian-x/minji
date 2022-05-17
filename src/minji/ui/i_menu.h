#pragma once

#include <limits>
#include <iostream>
#include <vector>
#include <memory>

#include "menu_opt.h"
#include "../core/deck.h"
#include "../core/deck.h"
#include "../core/answers/answer_type.h"
#include "../core/answers/answer_factory.h"
#include "../practice/practice_opt.h"
#include "../practice/practice.h"
#include "../utils/utils.h"

namespace ui
{
    void i_menu(std::vector<std::shared_ptr<minji::deck>> decks = {});
}
