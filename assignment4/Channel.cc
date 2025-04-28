#include "Channel.h"

Channel::Channel(const std::string& title, const std::string& owner): title(title), owner(owner) {}

Channel::~Channel() {
    for (int i = 0; i < mediaArray.getSize(); i++) {
        delete mediaArray[i];
    }
}

bool Channel::equals(const std::string& title) const {
    return this->title == title;
}

Media* Channel::get(int index) const {
    if (index < 0 || index >= mediaArray.getSize()) {
        cerr<<"Array index out of bounds"<<endl;
		exit(1);
    }

    return mediaArray[index];
}

int Channel::getSize() const {
    return mediaArray.getSize();
}

void Channel::print(ostream& ost) const {
    ost << "Title: " << title << "\nOwner: " << owner << endl;
}

void Channel::printWithMedia(ostream& ost) const {
    print(ost);

    for (int i = 0; i < mediaArray.getSize(); i++) {
        ost << "" << *mediaArray[i] << "\n";
    }
}

void Channel::add(Media* media) {
    mediaArray += media;
}

std::ostream& operator<<(std::ostream& ost, const Channel& channel) {
    channel.print(ost);
    return ost;
}