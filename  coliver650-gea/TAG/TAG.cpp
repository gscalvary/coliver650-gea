#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Canto defined classes.
#include <Test.h>

// The game engine will handle standard input via low-level windows console functions.  This allows the game to track the
// passage of time more realistically, without the interruptions that the use of cin would introduce.  Here the variables
// required for this feature are defined globally.
HANDLE hIn;
INPUT_RECORD inRec;
DWORD numRead, numEvents;
bool validateInput = false;
bool processInput = false;
char command = ' ';
string talkTarget;
unsigned bufferSize = 128;
int inputBytes = 1;
vector<char> inputBuffer;

// main() helper functions.
void processAsciiChar() {
	
	if (inRec.Event.KeyEvent.uChar.AsciiChar == '\r' || inputBuffer.size() >= bufferSize) {
		FlushConsoleInputBuffer(hIn);
		// Guard against validating input if the only input was [return].
		if (inputBuffer.size() > 0) {
			validateInput = true;
			cout << endl;
		}
	}
	else {
		if (inRec.Event.KeyEvent.uChar.AsciiChar == '\b') {
			if (inputBuffer.size() > 0) {
				inputBuffer.pop_back();
				cout << inRec.Event.KeyEvent.uChar.AsciiChar;
			}
		}
		else {
			inputBuffer.push_back(inRec.Event.KeyEvent.uChar.AsciiChar);
			cout << inRec.Event.KeyEvent.uChar.AsciiChar;
		}
	}
}

void getInput() {
	
	ReadConsoleInput(hIn, &inRec, inputBytes, &numRead);
	if (inRec.EventType == KEY_EVENT) {
		if (inRec.Event.KeyEvent.bKeyDown) {
			// Add code to unpause game.
			if (inRec.Event.KeyEvent.uChar.AsciiChar) {
				processAsciiChar();
			}
		}
	}
}

void run_tests() {
	
	cout << "Running Canto test suite..." << endl;

	// Initialize a test instance.
	Test cantoTest;

	// Test the Clock class.
	cantoTest.test_Clock_class();
	cout << endl << "Clock class tests complete." << endl;

	// Test the Game class.
	cantoTest.test_Game_class();
	cout << endl << "Game class tests complete." << endl;

	// Test the Point class.
	cantoTest.test_Point_class();
	cout << endl << "Point class tests complete." << endl;

	// Test the Player class.
	cantoTest.test_Player_class();
	cout << endl << "Player class tests complete." << endl;

	// Test the Message class.
	cantoTest.test_Message_class();
	cout << endl << "Message class tests complete." << endl;

	// Test the Npc class.
	cantoTest.test_Npc_class();
	cout << endl << "Npc class tests complete." << endl;

	// Test the circle class.
	cantoTest.test_Circle_class();
	cout << endl << "Circle class tests complete." << endl;

	cout << endl << "Tests are conducted using assertions so failures are written to console." << endl;
	cout << "No news is good news, all tests have passed!" << endl << endl;
	cout << "Press any key to continue." << endl;
	cin.ignore();
}

// main() the function that drives the game.
int main(int argc, char* argv[]) {

	// A parameter of 't' passed to the game runs its test suite only then exits.
	if (argc > 1) {
		if (*argv[1] == 't') {
			run_tests();
			return 0;
		}
	}

	// Create game objects.
	// - Introduction Messages
	Message oldmanMessage("The old man");
	oldmanMessage.addText("I am a humble denizen of the world below, here only to impart this:");
	oldmanMessage.addText("Learn as much as you can as you travel through my world back to yours but,");
	oldmanMessage.addText("do not stay too long lest your spirit erode trapping you there for eternity.");
	oldmanMessage.addText("And be wary, there are deceivers that will seek to harvest you.");
	oldmanMessage.addText("Only the truth will keep them from you.\n");
	Message descentMessage("game");
	descentMessage.addText("Then the earth of that grim cavern");
	descentMessage.addText("Began to shake so violently.");
	descentMessage.addText("A wind burst up from the ground to erupt red light and batter");
	descentMessage.addText("your senses - and so you fall, as though seized by sleep.");
	descentMessage.addText("...");
	// - Manual Message
	Message manualMessage("game");
	manualMessage.addText("type 'm' [enter] for this manual");
	manualMessage.addText("type 's' [enter] to get a sense of how you are feeling");
	manualMessage.addText("type 'l' [enter] to look about");
	manualMessage.addText("type 't <target>' <enter> to talk to someone");
	manualMessage.addText("type 'a', or 'b', or 'c' [enter] to respond to questions");
	manualMessage.addText("type 'd' [enter] to descend deeper into Canto");
	manualMessage.addText("type 'p' [enter] to pause the game");
	manualMessage.addText("type 'q' [enter] to quit the game");
	manualMessage.addText(" ");

	// - Canto I Messages
	// -- Virgil
	Message virgilMessage("Virgil");
	virgilMessage.addText("I tell you: we did not sin;");
	virgilMessage.addText("If we have merit, it can't suffice without");
	virgilMessage.addText("Baptism, portal to the faith you maintain.");
	// -- Socrates
	Message socratesMessage("Socrates the philosopher");
	socratesMessage.addText("Tell me traveler, why am I held here with so many");
	socratesMessage.addText("other men of science and philosophy from long ago?");
	socratesMessage.addText(" a) Betrayer of Country");
	socratesMessage.addText(" b) False counselor");
	socratesMessage.addText(" c) Unbaptized");
	// -- Circle Introduction
	Message cantoIMessage0("game");
	cantoIMessage0.addText("Breaking the deep sleep that filled your head,");
	cantoIMessage0.addText("With rested eyes you stand peering to find where you are");
	cantoIMessage0.addText("-- deep underground -- in truth, the lip");
	cantoIMessage0.addText("Above the chasm of pain, which holds the din");
	cantoIMessage0.addText("Of infinite grief: a gulf so dark and deep");
	cantoIMessage0.addText("And murky that though you gaze intently down");
	cantoIMessage0.addText("Into the canyon, you can see nothing below.");
	// -- Circle First Description
	Message cantoIMessage1("game");
	cantoIMessage1.addText("Here you pass through the woods - not trees,");
	cantoIMessage1.addText("But a wood of thronging spirits.");
	// - Canto I Npcs
	Npc virgilNpc("virgil", "shade", &virgilMessage);
	Npc socratesNpc("socrates", "demon", &socratesMessage);
	vector<Npc> cantoINpcs = { virgilNpc, socratesNpc };
	// - Canto I Circle
	vector<Message> cantoIMessages = { cantoIMessage0, cantoIMessage1 };
	Circle cantoICircle("Canto I", &cantoINpcs, 10, 'c', &cantoIMessages);

	// - Canto II Messages
	// -- Francesca
	Message francescaMessage("Francesca");
	francescaMessage.addText("Love, which in gentle hearts is quickly born,");
	francescaMessage.addText("Seized him for my fair body--which, in a fierce");
	francescaMessage.addText("Manner that still torments my soul, was torn");
	francescaMessage.addText("Untimely away from me.  Love, which absolves");
	francescaMessage.addText("None who are loved from loving, made my heart burn");
	francescaMessage.addText("With joy so strong that as you see it cleaves");
	francescaMessage.addText("Still to him, here.  Love gave us both one death.");
	// -- Minos
	Message minosMessage("Minos, a large demon,");
	minosMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	minosMessage.addText(" a) Heretics");
	minosMessage.addText(" b) Lustful");
	minosMessage.addText(" c) Violent to Others");
	// -- Circle Introduction
	Message cantoIIMessage0("game");
	cantoIIMessage0.addText("And now you can hear the notes of agony");
	cantoIIMessage0.addText("In sad crescendo beginning to reach your ear;");
	cantoIIMessage0.addText("Now you are where the noise of lamentation");
	cantoIIMessage0.addText("Comes at you in blasts of sorrow.  You are where");
	cantoIIMessage0.addText("All light is mute, with a bellowing like the ocean");
	cantoIIMessage0.addText("Turbulent in a storm of warring winds,");
	cantoIIMessage0.addText("The hurricane of Hell in perpetual motion");
	cantoIIMessage0.addText("Sweeping the ravaged spirits as it rends,");
	cantoIIMessage0.addText("Twists, and torments them.");
	// -- Circle First Description
	Message cantoIIMessage1("game");
	cantoIIMessage1.addText("As winter starlings riding on their wings");
	cantoIIMessage1.addText("Form crowded flocks, so spirits dip and veer");
	cantoIIMessage1.addText("Foundering in the wind's rough buffetings,");
	cantoIIMessage1.addText("Upward or downward, driven here and there");
	cantoIIMessage1.addText("With never ease from pain nor hope of rest.");
	// - Canto II Npcs
	Npc francescaNpc("francesca", "shade", &francescaMessage);
	Npc minosNpc("minos", "demon", &minosMessage);
	vector<Npc> cantoIINpcs = { francescaNpc, minosNpc };
	// - Canto II Circle
	vector<Message> cantoIIMessages = { cantoIIMessage0, cantoIIMessage1 };
	Circle cantoIICircle("Canto II", &cantoIINpcs, 10, 'b', &cantoIIMessages);

	// - Canto III Messages
	// -- Shade I
	Message cantoIIIShadeIMessage("Ciacco");
	cantoIIIShadeIMessage.addText("You see me soak to ruin in battering rain-");
	cantoIIIShadeIMessage.addText("But not alone, for all those around me share the same");
	cantoIIIShadeIMessage.addText("Penalty for the same transgression as mine.");
	cantoIIIShadeIMessage.addText("We are they who fed until our stomachs spilled over.");
	// -- Demon
	Message cantoIIIDemonMessage("Cerberus");
	cantoIIIDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoIIIDemonMessage.addText(" a) Gluttons");
	cantoIIIDemonMessage.addText(" b) Violent toward God");
	cantoIIIDemonMessage.addText(" c) Spenders and Hoarders");
	// -- Circle Introduction
	Message cantoIIIMessage0("game");
	cantoIIIMessage0.addText("Here is a realm of cold and heavy rain -");
	cantoIIIMessage0.addText("A dark, accursed torrent eternally pours");
	cantoIIIMessage0.addText("With changeless measure and nature.");
	cantoIIIMessage0.addText("Three-headed Cerberus, monstrous and cruel,");
	cantoIIIMessage0.addText("Barks doglike at the souls immersed here.");
	cantoIIIMessage0.addText("He claws the horde of spirits,");
	cantoIIIMessage0.addText("He flays and quarters them in the rain.");
	// -- Circle First Description
	Message cantoIIIMessage1("game");
	cantoIIIMessage1.addText("The wretches, howling like dogs where they are mired");
	cantoIIIMessage1.addText("And pelted, squirm about again and again,");
	cantoIIIMessage1.addText("Turning to make each side a shield for the other.");
	// - Canto III Npcs
	Npc cantoIIIShadeINpc("ciacco", "shade", &cantoIIIShadeIMessage);
	Npc cantoIIIDemonNpc("cerberus", "demon", &cantoIIIDemonMessage);
	vector<Npc> cantoIIINpcs = { cantoIIIShadeINpc, cantoIIIDemonNpc };
	// - Canto III Circle
	vector<Message> cantoIIIMessages = { cantoIIIMessage0, cantoIIIMessage1 };
	Circle cantoIIICircle("Canto III", &cantoIIINpcs, 10, 'a', &cantoIIIMessages);

	// - Canto IV Messages
	// -- Shade I
	Message cantoIVShadeIMessage("An ancient clergyman");
	cantoIVShadeIMessage.addText("Wrongness in how to give and how to have");
	cantoIVShadeIMessage.addText("Took the fair world from me and brought me this,");
	cantoIVShadeIMessage.addText("My ugly brawl, which words need not retirieve.");
	// -- Demon
	Message cantoIVDemonMessage("Plutus the defiler");
	cantoIVDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoIVDemonMessage.addText(" a) Gluttons");
	cantoIVDemonMessage.addText(" b) False counselors");
	cantoIVDemonMessage.addText(" c) Spenders and Hoarders");
	// -- Circle Introduction
	Message cantoIVMessage0("game");
	cantoIVMessage0.addText("Like waves above Charybdis, each crashing apart");
	cantoIVMessage0.addText("Against the one it rushes to meet, here gather");
	cantoIVMessage0.addText("People who hurry forward till they must meet.");
	cantoIVMessage0.addText("Each clutches a weight against his chest, and howls");
	cantoIVMessage0.addText("at his opponent each time they clash.");
	cantoIVMessage0.addText("Each wheels to roll his weight back round again");
	cantoIVMessage0.addText("To rush, collide painfully once more, and curse each other afresh.");
	// -- Circle First Description
	Message cantoIVMessage1("game");
	cantoIVMessage1.addText("Here they keep eternally returning");
	cantoIVMessage1.addText("To the two butting places: from the grave");
	cantoIVMessage1.addText("These will arise fists closed; and those, pates shining.");
	// - Canto IV Npcs
	Npc cantoIVShadeINpc("clergyman", "shade", &cantoIVShadeIMessage);
	Npc cantoIVDemonNpc("plutus", "demon", &cantoIVDemonMessage);
	vector<Npc> cantoIVNpcs = { cantoIVShadeINpc, cantoIVDemonNpc };
	// - Canto IV Circle
	vector<Message> cantoIVMessages = { cantoIVMessage0, cantoIVMessage1 };
	Circle cantoIVCircle("Canto IV", &cantoIVNpcs, 20, 'c', &cantoIVMessages);

	// - Canto V Messages
	// -- Shade I
	Message cantoVShadeIMessage("A shade");
	cantoVShadeIMessage.addText("(Unable to speak whole words) Once we were grim");
	cantoVShadeIMessage.addText("In the sweet air above, that took");
	cantoVShadeIMessage.addText("A further gladness in the play of the sun;");
	cantoVShadeIMessage.addText("Inside us, we bore acedia's dismal smoke.");
	cantoVShadeIMessage.addText("We have this black mire now to be grim in.");
	// -- Demon
	Message cantoVDemonMessage("Phlegyas the boatman");
	cantoVDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoVDemonMessage.addText(" a) Betrayer of Guests");
	cantoVDemonMessage.addText(" b) Wrathful and Sullen");
	cantoVDemonMessage.addText(" c) Violent toward Nature");
	// -- Circle Introduction
	Message cantoVMessage0("game");
	cantoVMessage0.addText("Here you travel through a great arc of swamp");
	cantoVMessage0.addText("all the while your eyes turned towards those who");
	cantoVMessage0.addText("Swallow the muck below lodged in the slime.");
	// -- Circle First Description
	Message cantoVMessage1("game");
	cantoVMessage1.addText("Others within the bog, all naked and muddy - with looks");
	cantoVMessage1.addText("Of fury, striking each other: with a hand");
	cantoVMessage1.addText("But also with their heads, chests, feet and backs.");
	// - Canto V Npcs
	Npc cantoVShadeINpc("shade", "shade", &cantoVShadeIMessage);
	Npc cantoVDemonNpc("phlegyas", "demon", &cantoVDemonMessage);
	vector<Npc> cantoVNpcs = { cantoVShadeINpc, cantoVDemonNpc };
	// - Canto V Circle
	vector<Message> cantoVMessages = { cantoVMessage0, cantoVMessage1 };
	Circle cantoVCircle("Canto V", &cantoVNpcs, 20, 'b', &cantoVMessages);

	// - Canto VI Messages
	// -- Shade I
	Message cantoVIShadeIMessage("Tisiphone");
	cantoVIShadeIMessage.addText("Here, lies those leaders of the faithless");
	cantoVIShadeIMessage.addText("Along with all the converts they made,");
	cantoVIShadeIMessage.addText("The followers of every sect, with like entombed with like.");
	// -- Demon
	Message cantoVIDemonMessage("Megaera of the Furies");
	cantoVIDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoVIDemonMessage.addText(" a) Unbaptized");
	cantoVIDemonMessage.addText(" b) Heretics");
	cantoVIDemonMessage.addText(" c) Violent towards God");
	// -- Circle Introduction
	Message cantoVIMessage0("game");
	cantoVIMessage0.addText("Here is a great plain filled with woe and torment.");
	cantoVIMessage0.addText("The ground is made uneven by tombs-around which arose flames");
	cantoVIMessage0.addText("That made the sepulchers glow with fiercer heat");
	cantoVIMessage0.addText("Than a smith could need.");
	// -- Circle First Description
	Message cantoVIMessage1("game");
	cantoVIMessage1.addText("Among these catacombs the lids were raised,");
	cantoVIMessage1.addText("With sounds of woe so great those within surely suffered horrible pain.");
	// - Canto VI Npcs
	Npc cantoVIShadeINpc("tisiphone", "shade", &cantoVIShadeIMessage);
	Npc cantoVIDemonNpc("megaera", "demon", &cantoVIDemonMessage);
	vector<Npc> cantoVINpcs = { cantoVIShadeINpc, cantoVIDemonNpc };
	// - Canto VI Circle
	vector<Message> cantoVIMessages = { cantoVIMessage0, cantoVIMessage1 };
	Circle cantoVICircle("Canto VI", &cantoVINpcs, 20, 'b', &cantoVIMessages);

	// - Canto VII Messages
	// -- Shade I
	Message cantoVIIShadeIMessage("Nessus");
	cantoVIIShadeIMessage.addText("These are the tyrants given to blood and plunder.");
	cantoVIIShadeIMessage.addText("Here they lament the merciless harm they did:");
	cantoVIIShadeIMessage.addText("Here is Alexander.");
	// -- Demon
	Message cantoVIIDemonMessage("Minotaur the unnatural");
	cantoVIIDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoVIIDemonMessage.addText(" a) Violent towards Others");
	cantoVIIDemonMessage.addText(" b) False counselor");
	cantoVIIDemonMessage.addText(" c) Betrayer of Country");
	// -- Circle Introduction
	Message cantoVIIMessage0("game");
	cantoVIIMessage0.addText("You see a broad moat bending in a curve");
	cantoVIIMessage0.addText("Full of blood in which boils many a soul.");
	// -- Circle First Description
	Message cantoVIIMessage1("game");
	cantoVIIMessage1.addText("Centaurs armed with bows and arrows speed in file.");
	cantoVIIMessage1.addText("They circle the moat by the thousands; if any soul should rise");
	cantoVIIMessage1.addText("Out of the blood more than its guilt makes lawful,");
	cantoVIIMessage1.addText("They pierce it with their arrows.");
	// - Canto VII Npcs
	Npc cantoVIIShadeINpc("nessus", "shade", &cantoVIIShadeIMessage);
	Npc cantoVIIDemonNpc("minotaur", "demon", &cantoVIIDemonMessage);
	vector<Npc> cantoVIINpcs = { cantoVIIShadeINpc, cantoVIIDemonNpc };
	// - Canto VII Circle
	vector<Message> cantoVIIMessages = { cantoVIIMessage0, cantoVIIMessage1 };
	Circle cantoVIICircle("Canto VII", &cantoVIINpcs, 30, 'a', &cantoVIIMessages);

	// - Canto VIII Messages
	// -- Shade I
	Message cantoVIIIShadeIMessage("Vanni");
	cantoVIIIShadeIMessage.addText("I must be thrust this far down because it was I");
	cantoVIIIShadeIMessage.addText("Who took adornments from the sacristy - ");
	cantoVIIIShadeIMessage.addText("For which another, falsely, was condemned.");
	// -- Demon
	Message cantoVIIIDemonMessage("A Malebranche overseer");
	cantoVIIIDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoVIIIDemonMessage.addText(" a) Violent towards God");
	cantoVIIIDemonMessage.addText(" b) Heretics");
	cantoVIIIDemonMessage.addText(" c) Thieves");
	// -- Circle Introduction
	Message cantoVIIIMessage0("game");
	cantoVIIIMessage0.addText("You stand on a bridge spanning a dark recess");
	cantoVIIIMessage0.addText("On the other side of the river of blood.");
	cantoVIIIMessage0.addText("You see in its confines serpents - a frightening swarm.");
	cantoVIIIMessage0.addText("Amid this horde, cruel, grim and dense,");
	cantoVIIIMessage0.addText("People were running, naked and terrified,");
	cantoVIIIMessage0.addText("Without a hope of hiding or a chance for safety.");
	// -- Circle First Description
	Message cantoVIIIMessage1("game");
	cantoVIIIMessage1.addText("Near you a serpent darts, and transfixes");
	cantoVIIIMessage1.addText("One at the point where neck and shoulders join.");
	cantoVIIIMessage1.addText("He takes fire and and burns and withers away,");
	cantoVIIIMessage1.addText("Sinking; and when his ashes come to rest");
	cantoVIIIMessage1.addText("The dust spontaneously resumes to its former shape.");
	// - Canto VIII Npcs
	Npc cantoVIIIShadeINpc("vanni", "shade", &cantoVIIIShadeIMessage);
	Npc cantoVIIIDemonNpc("malebranche", "demon", &cantoVIIIDemonMessage);
	vector<Npc> cantoVIIINpcs = { cantoVIIIShadeINpc, cantoVIIIDemonNpc };
	// - Canto VIII Circle
	vector<Message> cantoVIIIMessages = { cantoVIIIMessage0, cantoVIIIMessage1 };
	Circle cantoVIIICircle("Canto VIII", &cantoVIIINpcs, 30, 'c', &cantoVIIIMessages);

	// - Canto IX Messages
	// -- Shade I
	Message cantoIXShadeIMessage("Brutus");
	cantoIXShadeIMessage.addText("It is I who when Caesar saw me amongst the conspirators");
	cantoIXShadeIMessage.addText("He covered his face with toga and resigned to his fate.");
	cantoIXShadeIMessage.addText("And with that I was resigned to mine.");
	// -- Demon
	Message cantoIXDemonMessage("Lucifer");
	cantoIXDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoIXDemonMessage.addText(" a) Betrayers");
	cantoIXDemonMessage.addText(" b) Violent towards Others");
	cantoIXDemonMessage.addText(" c) Falsifiers");
	// -- Circle Introduction
	Message cantoIXMessage0("game");
	cantoIXMessage0.addText("Here the emperor of the realm of grief protrudes");
	cantoIXMessage0.addText("From mid-breast up above a surrounding lake of ice");
	cantoIXMessage0.addText("With three faces on his head.");
	// -- Circle First Description
	Message cantoIXMessage1("game");
	cantoIXMessage1.addText("The teeth of each mouth held a sinner, kept");
	cantoIXMessage1.addText("As by a flax rake: thus he held three of them");
	cantoIXMessage1.addText("In agony.");
	// - Canto IX Npcs
	Npc cantoIXShadeINpc("brutus", "shade", &cantoIXShadeIMessage);
	Npc cantoIXDemonNpc("lucifer", "demon", &cantoIXDemonMessage);
	vector<Npc> cantoIXNpcs = { cantoIXShadeINpc, cantoIXDemonNpc };
	// - Canto IX Circle
	vector<Message> cantoIXMessages = { cantoIXMessage0, cantoIXMessage1 };
	Circle cantoIXCircle("Canto IX", &cantoIXNpcs, 30, 'a', &cantoIXMessages);

	// - Canto X Messages
	// -- Shade I
	Message cantoXShadeIMessage("ShadeI");
	cantoXShadeIMessage.addText("");
	cantoXShadeIMessage.addText("");
	cantoXShadeIMessage.addText("");
	// -- Demon
	Message cantoXDemonMessage("Demon");
	cantoXDemonMessage.addText("Tell me traveler, of what are these shades guilty of being?");
	cantoXDemonMessage.addText(" a) Betrayer of Country");
	cantoXDemonMessage.addText(" b) False counselor");
	cantoXDemonMessage.addText(" c) Unbaptized");
	// -- Circle Introduction
	Message cantoXMessage0("game");
	cantoXMessage0.addText("");
	cantoXMessage0.addText("");
	cantoXMessage0.addText("");
	// -- Circle First Description
	Message cantoXMessage1("game");
	cantoXMessage1.addText("");
	cantoXMessage1.addText("");
	// - Canto X Npcs
	Npc cantoXShadeINpc("virgil", "shade", &cantoXShadeIMessage);
	Npc cantoXDemonNpc("socrates", "demon", &cantoXDemonMessage);
	vector<Npc> cantoXNpcs = { cantoXShadeINpc, cantoXDemonNpc };
	// - Canto X Circle
	vector<Message> cantoXMessages = { cantoXMessage0, cantoXMessage1 };
	Circle cantoXCircle("Canto X", &cantoXNpcs, 0, 'c', &cantoXMessages);

	// - Canto XI Messages
	// -- Circle Introduction
	Message cantoXIMessage0("game");
	cantoXIMessage0.addText("Climbing down the shaggy hide of lucifer");
	cantoXIMessage0.addText("What was up becomes what is down.");
	cantoXIMessage0.addText("For days you travel alone through an ill natural cavern");
	cantoXIMessage0.addText("Until at last...through a round aperture you see appear");
	cantoXIMessage0.addText("Some of the beautiful things that heaven bears");
	cantoXIMessage0.addText("Where you come forth, and once more see the stars.");
	// - Canto XI Npcs
	vector<Npc> cantoXINpcs;
	// - Canto XI Circle
	vector<Message> cantoXIMessages = { cantoXIMessage0 };
	Circle cantoXICircle("Canto XI", &cantoXINpcs, 0, ' ', &cantoXIMessages);

	// Initialize a game.
	vector<Circle> allCantos = 
		{ cantoICircle, cantoIICircle, cantoIIICircle, cantoIVCircle, cantoVCircle, cantoVICircle, 
		cantoVIICircle, cantoVIIICircle, cantoIXCircle, cantoXCircle, cantoXICircle};
	Game cantosGame(&allCantos);

	// Take control of standard console input.
	hIn = GetStdHandle(STD_INPUT_HANDLE);

	cout << "Welcome to Canto.\n" << endl;
	cout << "Your goal, traveler, is to emerge from Canto enlightened.\n" << endl;
	cout << "Press any key to continue..." << endl;
	cin.ignore();
	cout << "PRELUDE\n" << endl;
	cout << "...you come to a stop" << endl;
	cout << "Below a hill that marked one end of the valley" << endl;
	cout << "That had pierced your heart with terror, you look up\n" << endl;
	cout << "Toward the crest and see its shoulders already" << endl;
	cout << "Mantled in rays of that bright planet that shows" << endl;
	cout << "The road to everyone, whatever our journey.\n" << endl;
	cout << "Perhaps a weary traveler, perhaps suspended in dream," << endl;
	cout << "or perhaps passed from what you once knew," << endl;
	cout << "the way back from whence you came is obscure, diffuse and out of your reach." << endl;
	cout << "Only the way ahead is revealed by the first rays of dawn." << endl;
	cout << "And so while the dark valley watches you descend into the chilled," << endl;
	cout << "damp air of a cavern at the base of the large hill crouched before you.\n" << endl;
	cout << "As you enter, the faded image of an old man" << endl;
	cout << "slowly separates from the cavern mists and glides smoothly towards you." << endl;
	oldmanMessage.play();
	cout << "Press any key to learn the game commands...";
	cin.ignore();
	manualMessage.play();
	cout << endl << "Press any key to decend..." << endl;
	cin.ignore();
	descentMessage.play();
	// Play state introduction message.
	cantosGame.cantos->at(cantosGame.getCurrGameState()).playIntroduction();
	cout << "> ";

	// Game loop.
	while (true)
	{
		// Check for console input.
		while (true)
		{
			GetNumberOfConsoleInputEvents(hIn, &numEvents);
			if (numEvents > 0) {
				getInput();
			}
			else {
				break;
			}
		}

		// Validate input.
		if (validateInput) {
			validateInput = false;
			if (cantosGame.gameClock.getClockIsPaused()) {
				cantosGame.gameClock.unpauseClock();
				cout << "The game has resumed, welcome back traveler." << endl;
				cout << "Your current spirit is: " << cantosGame.gamePlayer.getSpirit() << " of 100." << endl;
			}
			// convert all user input to lower case
			for (unsigned i = 0; i < inputBuffer.size(); ++i) {
				char c = tolower(inputBuffer[i]);
				inputBuffer[i] = c;
			}
			// test for command validity
			switch (inputBuffer[0]) {
			case 'a':
			case 'b':
			case 'c':
				if (cantosGame.cantos->at(cantosGame.getCurrGameState()).isQuestionAsked()) {
					processInput = true;
					command = inputBuffer[0];
				}
				else {
					cout << "A question has not been asked of you here traveler, yet..." << endl << "> ";
				}
				break;
			case 'l':
			case 'd':
			case 'p':
			case 'q':
			case 'm':
			case 's':
				if (inputBuffer.size() > 1) {
					cout << inputBuffer[0] << " does not take arguments traveler." << endl;
					cout << "Please re-enter your command." << endl << "> ";
				}
				else {
					processInput = true;
					command = inputBuffer[0];
				}
				break;
			case 't':
				if (inputBuffer.size() <= 1) {
					cout << inputBuffer[0] << " takes a name as an argument, please re-enter your command." << endl << "> ";
				}
				else {
					talkTarget.clear();
					for (unsigned j = 1; j < inputBuffer.size(); ++j) {
						if (inputBuffer[j] != ' ') {
							talkTarget += inputBuffer[j];
						}
					}
					if (!talkTarget.empty()) {
						for (auto inhabitant = cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->begin();
							inhabitant < cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->end();
							inhabitant++) {
							if (inhabitant->getName() == talkTarget && inhabitant->getType() == "shade") {
								processInput = true;
								command = inputBuffer[0];
							}
						}
						if (!processInput) {
							cout << "You must be confused traveler, there is no one named " << talkTarget << endl;
							cout << " that wishes to speak." << endl << "> ";
						}
					}
					else {
						cout << inputBuffer[0] << " takes a name as an argument, please re-enter your command." << endl << "> ";
					}
				};
				break;
			default:
				cout << inputBuffer[0] << " is not a valid command traveler." << endl;
				cout << "Please re-enter your command or type 'm' [enter] for a list of commands." << endl;
				cout << "> ";
				break;
			}
			// Ready the inputBuffer for new input.
			inputBuffer.clear();
		}

		// Update the game with input, if any.
		if (processInput == true) {
			processInput = false;
			if (command == 'q') {
				break;
			}
			else {
				switch (command) {
				case 'a':
				case 'b':
				case 'c':
					// The player has offered the correct answer, record this.
					if (cantosGame.cantos->at(cantosGame.getCurrGameState()).getCorrectAnswer() == command) {
						cantosGame.gamePlayer.addCorrectAnswers(cantosGame.getCurrGameState());
					}
					// The player has offered an incorrect answer, record this.
					else {
						cantosGame.gamePlayer.addIncorrectAnswers(cantosGame.getCurrGameState());
					}
					// Move the game state forward based on the answers given.
					if (cantosGame.gamePlayer.getNumIncorrectAnswers() >= cantosGame.getIncorrectAnswerMax()) {
						cantosGame.updateGameState(9);
					}
					else {
						// If the last circle has been explored update game state to game over state.
						// Else move the game forward one state.
						if (cantosGame.getCurrGameState() == 8) {
							cantosGame.updateGameState(10);
						}
						else {
							cantosGame.updateGameState(cantosGame.getCurrGameState() + 1);
						}
					}
					// Play introduction messages.
					cout << "You enter a new area where:" << endl;
					cantosGame.cantos->at(cantosGame.getCurrGameState()).playIntroduction();
					break;
				case 'l':
					cantosGame.cantos->at(cantosGame.getCurrGameState()).playNextDescription();
					break;
				case 'd':
					cout << "You attempt to leave this area when...";
					for (auto inhabitant = cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->begin();
						inhabitant != cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->end();
						++inhabitant) {
						if (inhabitant->getType() == "demon") {
							inhabitant->speak();
							cantosGame.cantos->at(cantosGame.getCurrGameState()).setQuestionToAsked();
						}
					}
					break;
				case 'p':
					cantosGame.gameClock.pauseClock();
					cout << "The game is paused, entering any command will resume the game." << endl;
					cout << "Your current spirit is: " << cantosGame.gamePlayer.getSpirit() << " of 100." << endl;
					break;
				case 'm':
					manualMessage.play();
					break;
				case 's':
					cout << "Your current spirit is: " << cantosGame.gamePlayer.getSpirit() << " of 100." << endl;
					cout << "Letting your spirit reach 0 is bound to be trouble." << endl;
					break;
				case 't':
					for (auto inhabitant = cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->begin();
						inhabitant < cantosGame.cantos->at(cantosGame.getCurrGameState()).inhabitants->end();
						inhabitant++) {
						if (inhabitant->getName() == talkTarget) {
							inhabitant->speak();
						}
					}
					break;
				default:
					break;
				}
			}
			cout << "> ";
		}

		// Add code to deal with time passage.
		// -- erode spirit
		// Check spirit.
		// -- issue warning at 50, 25, 10
		// -- make the player a permanent resident at zero
		// If game state 9
		// -- If isThrown is false
		// ---- play message of siezure
		// ---- play message for redemption chance
		// ---- play question
		// ---- set new Player state to isThrown
		// -- else
		// ---- if player position == destination position
		// ------ update game status to 10
		// ---- else
		// ------ update position
		// ------ play warning as destination approaches

		// Game over state.
		if (cantosGame.getCurrGameState() == 10) {
			cout << "\nYour score is " << cantosGame.gamePlayer.getNumCorrectAnswers() << " out of 9 questions answered correctly.";
			cout << "\nThe game is over, thank you for playing!" << endl;
			cout << "Please press any key to continue.";
			cin.ignore();
			break;
		}
	}
	return 0;
}