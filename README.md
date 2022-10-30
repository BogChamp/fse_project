# Instructions for playing the game:

----
## Set up the game: 

### 1. Build the game locally (Ubuntu only): 
To download and start to play game, proceed with the following steps:
1) git clone git@github.com:BogChamp/fse_project.git
2) chmod +x prereqs.sh build.sh test.sh
3) run ./prereqs.sh
4) run ./build.sh
5) To play game: run ./hangman

To test game, run this:
run ./test.sh

### 2. Use Docker (recomended!):

**NB this way assumes you have Docker installed on your computer**

Run `docker build -t hangman-game .` inside the directory

After building the Docker image run `docker run -it --rm hangman-game`

To play run `make && ./hangman`

---
## Play the game:
![Example of the play](https://github.com/BogChamp/fse_project/blob/game/example.png?raw=true)

Input a letter. If you guessed one of word's letter, game will show letter's positions. 
Otherwise, you will lose 1 live. If you lose 5 lives, game will be ended.

----
