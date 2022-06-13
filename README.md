### 42 Cub3D

> ⚠️ **Warning**: Don't copy/paste code you don't understand: it's bad for you, and for the school.

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use
mathematics as a tool to create elegant and efficient algorithms.

## Description

The goal of this project was to create a basic first-person maze like the old Wolfenstein 3D, using raycasting.<br/>

<p align="center">
    <img img width="600" height="500" src="https://i.ibb.co/tq3Xcjs/screenshot.png">
</p>

**Features**<br/>

Mandatory part:
- A custom map can be create using a .cub file including :
  - Different wall textures that vary depending on which side the wall is facing (North, South, East, West).
  - Different floor and ceiling colors using RGB.
  - Doors and enemies position (X, Y).
  - The map file itself. (1 = wall, 0 = floor).
  - A player facing a direction (N, S, E, W)
- A 3D rendering of a map file.

Bonus part:
- Wall collisions.
- A minimap system.
- Doors which can open and close.
- Animated sprite (gun and enemies).
- Rotate the point of view with the mouse.
- Custom transparency.

Note: Our code does not contain the bonus part!

# Commands

**Key must be change between mac or linux in includes/cub3d.h or includes/cub3d_bonus.h**

| Key           | Command       |
| ------------- |:-------------:|
| <-- or -->    | Look left and right |
| W, A, S, D    | Move      |
| ESC           | Quit      |


# Resources

- <a href="http://users.atw.hu/wolf3d/">Original Wolfenstein 3D game</a>
- <a href="https://lodev.org/cgtutor/raycasting.html">Raytracing tutorial</a>
- <a href="https://github.com/qst0/ft_libgfx">X11 Event number</a>
- <a href="https://harm-smits.github.io/42docs/libs/minilibx">MinilibX 42 Docs</a>
- <a href="https://www.calculat.org/fr/aire-perimetre/triangle-rectangle.html">Right Triangle calculator</a>
- <a href="https://www.youtube.com/watch?v=eOCQfxRQ2pY">Wolfenstein 3D's map renderer video</a>
- <a href="https://www.youtube.com/watch?v=vYgIKn7iDH8">Rendering raycasting video</a>
- <a href="https://www.youtube.com/watch?v=NbSee-XM7WA&t=1393s">Super Fast Ray Casting in Tiled Worlds using DDA video</a>
