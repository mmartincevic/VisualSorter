
[![Actions Status](https://github.com/TheLartians/ModernCppStarter/workflows/Windows/badge.svg)](https://github.com/mmartincevic/CppSDLBoilerplate)
[![Actions Status](https://github.com/TheLartians/ModernCppStarter/workflows/Ubuntu/badge.svg)](https://github.com/mmartincevic/CppSDLBoilerplate)

<p align="center">
  <img src="https://repository-images.githubusercontent.com/254842585/4dfa7580-7ffb-11ea-99d0-46b8fe2f4170" height="175" width="auto" />
</p>

# C++ SDL starter project


### Build everything at once

You can build everything

```bash
cmake -S . -B build
cmake --build build
```

### Cleanup

You have two files inside bin/ directory. You can cleanup everything just by running simple command line:

```bash
./bin/cleanup.bat
```

### How to work with it

  1. Change project name i CMakeLists.txt
  2. Generate your solution files by running "cmake -S . -B build". This will output all files in build directory.
  3. You can directly open your solution and run it 
  4. If you add new files
    4.1. Take the route file -> new file and save it in appropriate location. 
    4.2. Once file added run, again, "cmake -S . -B build". This will regenerate your solution and reload it in place.
    4.3. Don't add files through solution explorer (this is a minor setback for a proper flow)
  

### TODO

  1. Ensure that you change the name in the CMakeLists.txt for the project. This will generate solution with that specified name.
  2. I've added example of the game rendering screen. You can customize everything in dimensions file, also add your own definitions.
  3. Added "functions" file for custom functions like getting random int or float, rendering SDL text.
  4. There also a simple state machine running. So you can have your menu, main game, exit screen ... you can extend it however you like it.
  5. Added support for SDL image and SDL ttf (drawing text).

### TODO

1. Add maybe separate project generations
2. Add proper testing (also with examples)
3. Add testing to cmake so we can run tests
4. Add clang formatting
5. Add documentation creation