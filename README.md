# Langstons-Ant
Langston's Ant Turing machine simulation written in C++

https://en.wikipedia.org/wiki/Langton%27s_ant

The rules of Langton’s Ant are very simple: the ant is placed onto the board that is filled with white spaces, and starts moving forward. For  each step forward, the Langton’s ant will follow 2 rules:

If the ant is on a white space, turn right 90 degrees and change the space to black.
If the ant is on a black space, turn left 90 degrees and change the space to white.

After that the ant moves to the next step and continues moving forward. The ant will follow these rules, and continue moving around the board, until the number of steps run out.

To replicate the "highway" phenomenon illustrated in the Langston's Ant wikipedia, select at least a 100 x 100 board with at least 11000 moves, then after the first step is executed select option 2 to execute every calculation step in the program and display the final result. For Windows, if your console screen is not large enough, right click the top of the window, click properties, and under 'layout' increase the size of your window.
