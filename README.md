# Rock Paper Scissors

The "optimal" strategy of RPS is to play random. This will result in equal
number of wins and losses. However, in a tournament with many sub-optimal
players, perhaps it is possible to take advantage of the other player's
shortcomings.

Can you make a bot that out-smarts the other bots, while at the same time
avoiding being out-smarted itself?

## Rules of the tournament
This program plays a round-robin tournament of Rock Paper Scissors between a
number of bots.

Each pair of bots plays a fixed number of games (currently 1000). The object
of the tournament is to achieve the highest total number of wins.

## Current list of bots

* NEXT        : This player always plays the move that beats the opponents last move.
* RANDOM      : This is the "optimal" strategy.
* CONST       : This player always plays the same move.
* COPY        : This player always copies the opponents last move.
* RANDOM_DIST : This player guesses what the opponent picks from the distribution of your last choices.
* MIKE        : The fantastic player that can predict the opponents next move :-)
* ASK         : The even more fantastic player that takes advantage of the fact that you can score a lot of points from the simple AIs :D
