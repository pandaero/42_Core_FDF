# 42_Core_FDF
FDF stands for "fil de fer", or wireframe. It is a 3D graphics project in the "second circle" of projects at 42. A graphics library is used as a basis to develop a topographic model with different projections.

## MiniLibX (MLX)
A minimalist graphical library that is used to create a window and show images.

### MLX Requirements
##### MacOS
On a 42 computer: use [Homebrew](https://github.com/kube/42homebrew) to install GLFW.
In the file:line /MLX42/MLX42_Int.h:22 change the username to the current one.
For compilation make sure to change the username in the Makefile as well.
##### Linux
Install GLFW:
- (Arch) sudo pacman -S glfw-x11 
- (Debian) sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
