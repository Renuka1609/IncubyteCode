## IncubyteCode
# Chandrayaan 3 Lunar Craft: Galactic Space Craft Control
# Galactic SpaceCraft
The Galactic SpaceCraft is a C++ program that simulates the movement of a spacecraft in three-dimensional space. This program allows you to control the spacecraft's position and orientation by providing a series of commands.

# Features
Move the spacecraft forward and backward in three dimensions (x, y, z).
Rotate the spacecraft 90 degrees to the left or right.
Turn the spacecraft upward or downward.
Execute a sequence of commands to navigate the spacecraft.

The program will execute a predefined sequence of commands ('f', 'r', 'u', 'b', 'l') and then display the final position and direction of the spacecraft.

# Command List
You can control the spacecraft using the following commands:

'f': Move forward one step.
'b': Move backward one step.
'l': Turn left (rotate 90 degrees counterclockwise).
'r': Turn right (rotate 90 degrees clockwise).
'u': Turn upward (change direction to 'U').
'd': Turn downward (change direction to 'D').
Understanding the Code

# Here's how it works:

The GalacticSpaceCraft class represents the spacecraft and provides methods for movement and orientation changes.
Commands are executed using the executeCommands method by providing a sequence of characters.
The spacecraft's position and direction can be obtained using getCurrentPosition and getCurrentDirection methods.
