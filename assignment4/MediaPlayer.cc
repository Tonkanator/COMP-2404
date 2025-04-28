#include "MediaPlayer.h"
#include <fstream>
#include <string>

std::ostream& operator<<(MediaPlayer& player, const Media& media) {
    player.play(std::cout, media);
    return std::cout;
}

void AudioPlayer::play(std::ostream&ost, const Media& m) const {
    ost << "Audio: " << m.getAudio() << std::endl;
}

void VideoPlayer::play(std::ostream&ost, const Media& m) const {
    AudioPlayer::play(ost, m);

    std::ifstream videoFile(m.getVideoFile());
        if (videoFile) {
            std::string line;
            while (getline(videoFile, line)) {
                ost << line << "\n";
            }
            videoFile.close();
        } else {
            ost << "Error: Could not open video file " << m.getVideoFile() << "\n";
        }
}