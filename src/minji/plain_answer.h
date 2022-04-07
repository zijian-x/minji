#pragma once

#include <iostream>
#include <string>

#include "answer.h"

namespace minji
{
	class plain_answer : public answer
	{
	public:
		plain_answer(std::string) noexcept;
		bool operator==(const plain_answer&) const;

	private:
		std::string _ans;

		std::ostream& output(std::ostream&) const override;
	};
}