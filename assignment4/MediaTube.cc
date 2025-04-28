#include "MediaTube.h"

MediaTube::~MediaTube() {
    for (int i = 0; i < channelArray.getSize(); i++) {
        delete channelArray[i];
    }
}

void MediaTube::addChannel(Channel* channel) {
    channelArray += channel;
}

void MediaTube::addMedia(Media* media, const std::string& channelTitle) {
    for (int i = 0; i < channelArray.getSize(); i++) {
        if (channelArray[i]->equals(channelTitle)) {
            channelArray[i]->add(media);
            return;
        }
    }

    cerr << "Error: Channel not found" << endl;
}

const Array<Channel*>& MediaTube::getChannels() const {
    return channelArray;
}

Channel* MediaTube::getChannel(int index) {
    if (index < 0 || index >= channelArray.getSize()) {
        cerr << "Error: Channel at index not found" << endl;
        exit(1);
    }

    return channelArray[index];
}

Channel* MediaTube::getChannel(const std::string& title) {
    for (int i = 0; i < channelArray.getSize(); i++) {
        if (channelArray[i]->equals(title)) {
            return channelArray[i];
        }
    }

    cerr << "Error: Channel with title not found" << endl;
    exit(1);
}

void MediaTube::getMedia(Search& search, Array<Media*>& mediaOutput) {
    
    for (int i = 0; i < channelArray.getSize(); i++) {
        Channel* channel = channelArray[i];

        for (int j = 0; j < channel->getSize(); j++) {
            Media* media = channel->get(j);
            if (search.matches(media)) {
                mediaOutput += media;
            }
        }
    }
}