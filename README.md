# Snake
Snake game in c++ using graphics library dynamically at runtime

#### NOTE THIS WAS BUILT ON MAC AND WAS NOT MADE FOR CROSS PLATFORM

## SETUP

To setup the game have the following
```
brew
cmake
clang++
```
now run the following commands
```
git clone https://github.com/ChazniK/nibbler.git && cd nibbler
make
```

if you have all the depencies mentioned above it will attempt to download the required graphics library needed.
This part will take few seconds to compile.
After compiling you can now run
```
./nibbler
```

## MENU
running nibbler you'll start off at menu in which you can set some settings, 
select single player or multiplayer.

The settings menu will allow you to change amount of lives, the difficulty(this increase your speed more).
You can also change the default screen resolution here

## CONTROLS
```
ESC = exit game/menu
F1 = use sfml graphics library
F2 = use sdl graphics library
F3 = use glfw graphics library
ARROW_UP = move up
ARROW_DOWN = move down
ARROW_LEFT = move left
ARROW_RIGHT = move right
BUTTON_W = move player 2 up
BUTTON_A = move player 2 left
BUTTON_S = move player 2 down
BUTTON_D = move player 2 right
ENTER = select option in menu
```

## AUTHOR
Chazni - logic
Marco - graphics
