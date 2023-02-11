#include <string>

using namespace std;

struct song {
	string name;
	string artist;
	string performers;
};

song track_one;
song track_two;
song track_three;

void create_track_data() {
	track_one.name = "One";
	track_two.name = "Two";
	track_three.name = "Three";

	track_one.artist = "One Artist";
	track_two.artist = "Two Artist";
	track_three.artist = "Three Artist";

	track_one.performers = "One Performers";
	track_two.performers = "Two Performers";
	track_three.performers = "Three Performers";
}
