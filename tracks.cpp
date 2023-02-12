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
song track_four;
song track_five;
song track_six;
song track_seven;
song track_eight;

void create_track_data() {
	track_one.name = "In The Virtual End";
	track_two.name = "Grinch's Ultimatum OST";
	track_three.name = "Reconstruct";
	track_four.name = "Blocks";
	track_five.name = "Dream On";
	track_six.name = "Da Funk";
	track_seven.name = "Aerodynamic";
	track_eight.name = "Song";

	track_one.artist = "Linkin Park";
	track_two.artist = "PilotRedSun";
	track_three.artist = "Jerobeam Fenderson";
	track_four.artist = "Jerobeam Fenderson";
	track_five.artist = "Aerosmith";
	track_six.artist = "Daft Punk";
	track_seven.artist = "Daft Punk";
	track_eight.artist = "Jake Chudnow";

	track_one.performers = "Ray Koefoed";
	track_two.performers = "a rock";
	track_three.performers = "Jerobeam Fenderson";
	track_four.performers = "Jerobeam Fenderson";
	track_five.performers = "Aerosmith";
	track_six.performers = "Daft Punk";
	track_seven.performers = "Daft Punk";
	track_eight.performers = "Jake Chudnow";
}
