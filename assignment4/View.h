#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Channel.h"
#include "MediaPlayer.h"

using namespace std;

class View {
		
	public:
		//constructors
		View();
		void menu(vector<string>&, int& choice);
		void printAllChannels(const Array<Channel*>& channels);
		void channelMenu( const Array<Channel*>& channels, int& choice);
		void printChannel(const Channel*);
		// void mediaMenu(Channel&, int& choice);
        void promptOwner(string& owner);
		void promptCategory(string& category);
		void printPlaylist(Array<Media*>&);
		void playPlaylist(Array<Media*>&);

		void promptVideo();
		void toggleVideo(bool);


	private:
		// void loadAudioPlayer();
		// void loadVideoPlayer();
		MediaPlayer* player;
		AudioPlayer audioPlayer;
		VideoPlayer videoPlayer;
};
#endif