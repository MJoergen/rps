# Rock Paper Scissors

The "optimal" strategy of RPS is to play random. This will result in equal
number of wins and losses. However, in a tournament with many sub-optimal
players, perhaps it is possible to take advantage of the other player's
shortcomings.

Can you make a bot that out-smarts the other bots, while at the same time
avoiding being out-smarted itself?

## Building from source
    make

## Rules of the tournament
This program plays a round-robin tournament of Rock Paper Scissors between a
number of bots.

Each pair of bots plays a fixed number of games (currently 1000). The object
of the tournament is to achieve the highest total number of wins.

## Current list of bots

* NEXT        : This player always plays the move that beats the opponents last move.
* RANDOM      : This is the "optimal" strategy.
* CONST       : This player always plays the same move.
* CONST_2     : This player usually plays the same move, but occasionally changes strategy.
* COPY        : This player always copies the opponents last move.
* RANDOM_DIST : This player guesses what the opponent picks from the distribution of your last choices.
* MIKE        : The fantastic player that can predict the opponents next move :-)
* ASK         : The even more fantastic player that takes advantage of the fact that you can score a lot of points from the simple AIs :D
* CYCLE       : Another stupid player that just cycles through the three possible moves.
* MIKE_2      : A new and improved version of MIKE with an outstanding AI :-)
* CYCLE_2     : A cycle player that occasionally changes direction.
* CYCLE_3     : Another cycle player that occasionally "misses a step", i.e. repeats the last move.
* MIKE_3      : The incarnation of SkyNet.
* NEXT_2      : Slightly more intelligent version of NEXT, that tries to detect if the opponent has figured out its strategy.
* ANTI_NEXT   : Specifically designed to win against the NEXT strategy.
* MADS        : Uses a normal distribution to predict the move of its opponents.
* MIKE_4      : Call Sarah O'Connor. NOW!
* ANTI_MIKE   : A (somewhat) successfull attempt to gain points over MIKE_4
* DELAY       : A more unpredictable version of NEXT.
* TERMINATOR  : A bot that recognizes its opponent!

