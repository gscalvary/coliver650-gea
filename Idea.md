# Introduction #

Notes regarding how I would like the game to work.


# Details #

Game Name: Canto

Goal: Emerge enlightened.  The player emerges from their journey with a brief taste of the world described in Dante's Inferno as translated by the great Robert Pinsky.  A score from 0 - 9 will be awarded based on the correct answers given to the demon questions.

The player, or Traveler, must learn why the occupants of this underworld are there, of what are they guilty?  If they successfully explore the underworld (Hell) and demonstrate understanding then they will be allowed to leave (win), else they will become another permanent resident (loss).

The Traveler's human spirit can only withstand each circle a specific period of time.  as the player spends time in a circle their spirit erodes from a value of 100 to 0.  The time period it takes for a full erosion gets shorter as the Traveler descends.  Periodically the game will warn the player of impending danger as their spirit erodes.  Letting their spirit reach zero will cause the player to be banished to where-ever the slothful or lazy are punished (3rd Circle, Gluttons, creative license!).  This is a loss state.

Before being allowed to descend the demon that lords over the circle will ask the Traveler of what sin the tormented are guilty.  The Traveler is always allowed to pass as the demons will lie if they give an incorrect answer by telling them it was correct.  After accumulating x incorrect answers the Traveler will be seized and sent to permanently dwell with the falsifiers, 8th circle, pouch 10 (another lose state).  Yay, more creative license!  However, the player is given a chance, by those whose will makes things be, for redemption.  If they are able to answer a formerly incorrect answer correctly they will be placed "safely" into the circle into which they were trying to descend.

Actions:
(L)ook: use an array of strings advancing the index to reveal more Inferno text
(T)alk Target: illicit stories from the underworld inhabitants, reveal more Inferno text.
(D)escend: attempt to move to the next circle.
(P)ause: allow the player to pause the game.
(Q)uit: quit the game.
(M)anual: list of game actions.

Choose an answer to the demon's question:
(A)
(B)
(C)



Introduction

Perhaps a weary traveler, perhaps suspended in dream, or perhaps passed from what you once knew.  The way back is obscured, diffuse and out of reach.  Only the way ahead is revealed by the first rays of dawn.  And so while the dark valley watches you descend into the chilled, timeless air of a cavern at the base of the large hill crouched before you.

Barely discernable in a distant dim recess an elderly man, whose image seems nearly to fade, waits patiently for you.




Canto I (Limbo, 1st Circle - The Unbaptized)
gameState == 0

Canto II (2nd Circle - The Lustful)
gameState == 1

Canto III (3rd Circle - Gluttons)
gameState == 2

Canto IV (4th Circle - Spenders & Hoarders)
gameState == 3

Canto V (5th Circle - The Wrathful & Sullen)
gameState == 4

Canto VI (6th Circle(Dis) - Heretics)
gameState == 5

Canto VII (7th Circle - Violent) Do the suicide, ring 2.
gameState == 6

Canto VIII (8th Circle - Those who are fraudulent)
gameState == 7

Canto IV (9th Circle - The betrayers)
gameState == 8

Chance for Redemption
gameState == 9

Game Over
gameState == 10


Emergence (Win)

or...

Permanent Resident(Loss)