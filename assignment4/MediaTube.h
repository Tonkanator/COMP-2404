#ifndef MEDIATUBE_H
#define MEDIATUBE_H

#include "Channel.h"
#include "Search.h"

class MediaTube {
    private:
        Array<Channel*> channelArray;
    public:
        ~MediaTube();
        void addChannel(Channel* channel);
        void addMedia(Media* media, const std::string& channelTitle);
        const Array<Channel*>& getChannels() const;
        Channel* getChannel(int index);
        Channel* getChannel(const std::string& title);
        void getMedia(Search& search, Array<Media*>& mediaOutput);
};

#endif