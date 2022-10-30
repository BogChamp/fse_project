# Instructions for playing the game:

----
## Build the game locally: 
To download and start to play game, proceed with the following steps:
1) git clone git@github.com:BogChamp/fse_project.git
2) chmod +x prereqs.sh build.sh test.sh
3) run ./prereqs.sh
4) run ./build.sh
5) To play game: run ./hangman

To test game, run this:
run ./test.sh

## Play with docker file (recomended!):

**NB this way assumes you have Docker installed on your computer**

Run `docker run -t hangman-game .` inside the directory
How to play the game:
<img width="964" src=“https://github.com/BogChamp/fse_project/blob/game/example.png”>
![alt text](https://github.com/BogChamp/fse_project/blob/game/example.png?raw=true)

Input a letter. If you guessed one of word's letter, game will show letter's positions. 
Otherwise, you will lose 1 live. If you lose 5 lives, game will be ended.

----

## Play with docker file 
