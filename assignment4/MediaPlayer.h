#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "Media.h"

class MediaPlayer {
    public:
        virtual void play(std::ostream& ost, const Media& m) const = 0;
        friend std::ostream& operator<<(MediaPlayer& player, const Media& media);
};

class AudioPlayer: public MediaPlayer {
    public:
        void play(std::ostream&ost, const Media& m) const override;
};

class VideoPlayer: public AudioPlayer {
    public:
        void play(std::ostream&ost, const Media& m) const override;
};

#endif