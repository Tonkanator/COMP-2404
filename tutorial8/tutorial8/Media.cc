#include "Media.h"

Media::Media(const std::string& channelTitle, const std::string& owner, const std::string& mediaTitle, const std::string& category, const std::string& audioContent, const std::string& videoFile)
    :channelTitle(channelTitle), owner(owner), mediaTitle(mediaTitle), category(category), audioContent(audioContent), videoFile(videoFile) {}

std::string Media::getChannel() const {
    return channelTitle;
}

std::string Media::getOwner() const {
    return owner;
}

std::string Media::getMedia() const {
    return mediaTitle;
}

std::string Media::getCategory() const {
    return category;
}

std::string Media::getAudio() const {
    return audioContent;
}

std::string Media::getVideo() const {
    return videoFile;
}

void Media::print(std::ostream& ost) const {
    ost << "Channel Title: " << channelTitle << ", Owner: " << owner
        << ", Category: " << category << ", Media Title: " << mediaTitle;
}

std::ostream& operator<<(std::ostream& ost, const Media& media) {
    media.print(ost);
    return ost;
}