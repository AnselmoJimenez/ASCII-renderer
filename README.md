# ASCII-Renderer

## Contents
- [Overview](#Overview)
- [Install](#Install)
- [Usage](#Usage)
    - [Supported Shapes](#Supported-Shapes)

## Overview
Welcome to the README for my ASCII Renderer. Inspired by Andy Sloane's `donut.c`, I have created a similar project that renders various spinning objects with ASCII characters. The goal of this project is to learn how 3D objects were rendered and get somewhat of an introduction to 3D graphics. In its current state, the 3D shapes available to render are cubes, cones, cylinders, and spheres. In the future I would like to open up the implementation for other shapes and perhaps more complex 3D objects. For more information on how ascii rendering works, I will direct you to Andy Sloane's Blog where he went into full detail behind the math that allows the rendering to take place, [Donut math: How donut.c works](https://www.a1k0n.net/2011/07/20/donut-math.html).

## Install
1. Clone the repository to your local machine
```bash
git clone https://github.com/AnselmoJimenez/ASCII-renderer.git
```
2. Navigate to the project directory
```bash
cd ASCII-renderer
```
3. Build the project using the provided Makefile
```bash
make
```
This compiles the project and generates an executable named `render` that you can use for rendering the shapes

## Usage
To use the ASCII-renderer, you can run the generated executable with `-s` and the desired shape as a command-line argument. For example, to render a cube, you can use the following command:
```bash
./render -s cube
```
You can replace `cube` with the name of any of the current supported shapes.

### Supported Shapes
Currently, the ASCII Renderer supports the following 3D shapes:
* Cube
* Cylinder
* Cone
* Sphere