#include "Search.h"

std::ostream& operator<<(std::ostream& ost, const Search& search) {
    search.print(ost);
    return ost;
}

O_Search::O_Search(const std::string& owner): owner(owner) {}

bool O_Search::matches(const Media* media) const {
    return media->getOwner() == owner;
}

void O_Search::print(std::ostream& ost) const {
    ost << "Search by Owner: " << owner;
}

C_Search::C_Search(const std::string& category): category(category) {}

bool C_Search::matches(const Media *media) const {
    return media->getCategory() == category;
}

void C_Search::print(std::ostream &ost) const {
    ost << "Search by Category: " << category;
}

OorC_Search::OorC_Search(const std::string& owner, const std::string& category): O_Search(owner), C_Search(category) {}

bool OorC_Search::matches(const Media *media) const {
    return O_Search::matches(media) || C_Search::matches(media);
}

void OorC_Search::print(std::ostream &ost) const {
    ost << "Search by Owner or Category: " << owner << ", " << category;
}