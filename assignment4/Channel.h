#ifndef CHANNEL_H
#define CHANNEL_H

#include "Array.h"
#include "Media.h"

class Channel {
    private:
        Array<Media*> mediaArray;
        std::string title, owner;
    public:
        Channel(const std::string& title, const std::string& owner);
        ~Channel();
        bool equals(const std::string& title) const;
        Media* get(int index) const;
        int getSize() const;
        void print(ostream& ost) const;
        void printWithMedia(ostream& ost) const;
        void add(Media* media);
        friend std::ostream& operator<<(std::ostream& ost, const Channel& channel);
};

#endif