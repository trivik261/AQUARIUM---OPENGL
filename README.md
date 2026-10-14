# Interactive Aquarium — OpenGL

A 2D aquarium built with C++ and GLUT: fish motion, plants, sand, bubbles, feeding, and poisoned-food scenes.

## Native build
```bash
sudo apt-get install g++ freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
make
./build/aquarium
```
An OpenGL-capable graphical session is required. Right-click to select a scene. Keyboard shortcuts: **1** feeding, **2** play, **3** poisoned food, **Q / Esc** exit. The original GLUT drawing and scene logic are retained. Keyboard controls make the existing menu accessible without a mouse.

The browser portfolio includes a Canvas adaptation of the aquarium concept. It is a separate browser implementation, not the native OpenGL program compiled to WebAssembly. Native scene timing follows the original frame-based animation and can vary by computer.
