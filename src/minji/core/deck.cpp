#include <memory>

#include "deck.h"

namespace minji
{
    deck::deck(std::string name)
        : name_(std::move(name))
    {
    }

    void deck::add(card c) { cards_.push_back(std::move(c)); }

    void deck::remove(std::vector<card>::iterator it) { cards_.erase(it); }

    void deck::replace(std::vector<card>::iterator it, card c)
    {
        *it = std::move(c);
    }

    std::string& deck::name() { return name_; }

    const std::string& deck::name() const
    {
        return const_cast<deck*>(this)->name();
    }

    void deck::show_card(
        std::ostream& os, size_t idx, answer::reveal reveal) const
    {
        cards_[idx].show(os, reveal);
    }

    void deck::show_answer(std::ostream& os, size_t idx) const
    {
        os << cards_[idx].back();
    }

    size_t deck::size() const { return cards_.size(); }

    bool deck::operator==(const deck& rhs) const
    {
        return this->name_ == rhs.name_ && this->cards_ == rhs.cards_;
    }

    card& deck::operator[](size_t i) { return cards_[i]; }

    const card& deck::operator[](size_t i) const
    {
        return const_cast<deck*>(this)->operator[](i);
    }

    std::vector<card>::iterator deck::begin() { return cards_.begin(); }

    std::vector<card>::const_iterator deck::begin() const
    {
        return cards_.begin();
    }

    std::vector<card>::iterator deck::end() { return cards_.end(); }

    std::vector<card>::const_iterator deck::end() const { return cards_.end(); }

}
