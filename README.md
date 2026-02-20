*This project has been created as part of the 42 curriculum by haskalov*

## Description

This project is small 2d-video game with graphic library MiniLibX


### Compilation

Compile program use make (or make re) If is there some problem with compilation, use both make re and after make.


### Use 

start game:  ./so_long


## Instructions

You can move player (mouse) by keys up-down-left-right (or W-S-A-D )
You have collect all the collectibles (cheese) and after you have to move to exit (mouse hole).
If you sucesfully finish the game, windou will close and you win.


## Resources

Minilibx documentation https://harm-smits.github.io/42docs/libs/minilibx

https://medium.com/@jalal92/understanding-the-minilibx-a-practical-dive-into-x-window-programming-api-in-c-cb8a6f72bec3

https://github.com/augustobecker/so_long

AI used well for explanation new terms and functions + for helping understand where all segfaults and leaks come from


### Testers

DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer (for segfault + memory leaks)



