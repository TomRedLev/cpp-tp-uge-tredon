# tower_control
guide planes to land safely

### Requirements

The following software is necessary to compile and run the program
1. C++ compiler capable of compiling C++-17 code (for example, gcc version 8 or above)
2. glut or freeglut
3. OpenGL version 1.1 or above
4. CMake version 3 or above to generate the project

### Installation of FreeGLUT

We recommand that you use FreeGLUT rather than GLUT, since the latter hasn't been updated since 1998, and its licence prevents anyone to do so.

#### Linux
just use your favorite package manager to install it (apt-get, snap, pacman, or whatever).

#### Mac
install using the package manager (`brew`)

**attention**:
for maxOS > 10.8, you'll need to install and run XQuartz

**troubleshoot**:
If you get messages like `<some lib> was built for newer macOS version (XX) than being linked (XX)` try updating/installing `glut` avec brew!

#### Windows
Go to this [page](http://freeglut.sourceforge.net/) and select the latest stable release to get the source code.\
Then open the folder with VSCode, and run `CMake: Configure` command.

Once the project is configured, open the `CMakeCache.txt` file that should have been generated inside the `build` folder.\
Look for `CMAKE_INSTALL_PREFIX`, which indicates where on your computer the library will be installed. Modify this location if the default one doesn't suit you.\
Save the file and run `CMake: Configure` once again, to apply the changes.

Run the `CMake: Build` command on the [ALL_BUILD] target, and wait for the build to finish.\
If it succeeds, then you can run `CMake: Install`.

If you installed the library in an exotic location, you will need to indicate it to CMake.
To do so, modify the `CMAKE_PREFIX_PATH` environment variable (or create it if it doesn't exist yet), and add the installation folder of the library in it.
If it already contains a path, you can append another one by separating it with `;` (do not add any space before or after it). 

### Build

To build the program, it should be sufficient to enter the top-level directory and type
```
cmake .
make
```

### Default Keyboard Shortcuts
|key | action |
|----|--------|
|x,q | exit   |
|f   | toggle fullscreen |
|+/- | zoom in/out|
|c   | create random aircraft |
