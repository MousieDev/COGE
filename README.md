# About COGE
A Simple Engine in its very first stages of becoming a, Game Engine or just a framework for making games using OpenGL.

I didn't really know what to name this engine so I just call it:
    cOOPgraphicsEngine or COGE

Due to the fact that it uses structs and very OOP-like... methods

# Features of COGE:

 ### OpenGL 4.1:
	Modern OpenGL and makes my life way easier, like a lot but still does not have access to certain functions
	
 ### Header-Only Files:
	VBO, VAO, IBO..etc.. don't really have .c files and just one header file which contains all the necessary functions to make it easier to manage the files

 ### VAOs, IBOs, VBOs:
	Abstracted so now it works very similar to the OOP way I did in C++ but instead uses structs and is more centered to the struct

 ### OOP Without Classes:
	Think without the class...
	So.. the class character in C++ would look like:
   
	    class Character {
		public: 
		    Character(int x, int y, int z, const std::string& name);
		    ~Character();

		    void SetName(const std::string& name);
		    std::string GetName();

		    int SetX(int x);
		    int SetY(int y);
		    int SetZ(int z);	
				
		    int GetX();
		    int GetY();
		    int GetZ();


		private:
		    int x, y z;	
		    std::string name;

	    };
	
	Now in C it would become a struct only containing the data:
		
	    typedef struct {
		int x, y, z;
		const char * name;
	    } Character;
	    
	Now the methods, first off, structs don't have any private vairables so intialization can be done just by declaring a variable of the type Character and then assigning whatever we want and we don't really need anything like setters and getters neither.. so it seems that we are basically done.. as everything can be done like this:
	    
	    Character character = { .x = 10, .y = 120, .z = 21, .name = "Lol"  };
	    
	    // Setting New Name
	    character.name = "new";

	    // Setting X
	    character.x = 10;
	    // And I think you get the idea...


 ### Shader Loading & Uniforms:
	C File API, credits to: https://github.com/templalizer1284/cshader & Uniforms are set using the glUniform... functions

 ### Textures:
	Loading:
	    Just good ol' stb_image.h doing the work for me

	Binding:
	    Just takes in which slot to bind to and then I'm done

 ### Inputs:
	{ Joysticks
	Keyboard
	Mouse } :
		    Basically just the classes written by Michael Grieco in his OpenGL series but without the classes and more simplified and easier to use in my opinion.

    Little Abstraction:
	Still pretty bare-bones Engine

    Makefile/SH Script to Compile:
	Very easy to setup

    Test Class:
	GLFWwindow * window
	Program Props:
	    VBO, IBO, VAO = { 1, 1, 1 }:
		1 for everthing to encourage using just 1 of everything to store what I need, encourages batching...
	Init
	Update
	Render
	Clean

	Now the test class was implemented in a very interesting way...I first made functions for:
	    Init();
	    Update();
	    Render();
	    Clean();

	And some more utility functions

	Then I made a new header for the type of test I want, as of now just the DevelopmentTest.h and then in that I define the functions:
	    Init();
	    Update();
	    Render();
	    Clean();

	Then in the Main.c, I just call a function called Run which just calls the Functions:
	    Init();
	    Update();
	    Render();
	    Clean();

	This is basically inheritance in C without OOP

	This makes it more easier for me and I don't have to include the OpenGL headers and basically just get done just like that.

 ### GitHub:
	VERSION CONTROL
	Contribution from other people
	You guys can finally see the engine's progress

 ### Written in Pure C89:
	No complicated stuff, quite basic and should be very easy to port, might even work in C++...

 ### Logging Library:
	Prints messages, warnings, and errors easily but does give off some warnings and it uses ANSI colors and makes the output colored

 ### Test-Like Class [Not Actual Class But Just Functions]:
	Test-Like Class header file for making rapid tests

# Features to be implemented in COGE:

 ### Batch Renderer:
	Abstraction
	Adding & Removing

 ### Test Menu:
	Displays all the tests in the Tests folder

 ### Nuklear Support:
	Basically ImGui but for C OpenGL

 ### 3D
 ### Maths Engine:
	Matrices:
	    Matrix, 4x4, 3x3:
		Quite important for transformations and I need to implement project matrix so this is essential
	
	Quaternions:
	    For 3D rotation and is not limited by something known as the Gimbal Lock, basically the best method for rotation

	Vectors:
	    This is something that I will have to implement just like matrices but it is a little bit easier and I think I will have to make around 3 different structs for vec2, vec3, vec4


	More:
	    Anything related to maths...for example finding the distance between 2 points..

	
 ### Engine-Like Functions:
	Collision Detection..etc..

 ### Debugging:
	Make it easier to see variables at runtime or something...don't really know what to do here..:/

 ### Organization:
	Headers that are being included could be put into more sub-directories, GLFW could be added to some folder valled vendor or something..

 ### Abstraction:
	Basically anything that can be simplified further and just makes the life of the developer easier 

 ### Comments:
	Maybe contributes to the documentation when working with the functions..? Like when you hover over a function it shows the function description so something like that...	

 ### Documentation:
	HTML, CSS, JS Docs... Would be very interesting to see as I can work on web development skills :DDD

 ### Ninja Build System:
	According to MousieDev, this thing is very very fast and maybe even better than Make...
	
 ### Vulkan, GL ES:
	Support for other graphical APIs
	#if defines will be very useful

 ### Web:
	Build for web

 ### Builds:
	Multi-Platform Compilation?

# Getting the COGE:
	- Mac:
		run:
			bash run-mac.sh
			./app
			
	- Linux (Ubuntu Only :/):
		run:
			bash run-linux.sh
			./app
			
	- Windows:
		run:
			Coming soon...


# Credits to:

    https://github.com/templalizer1284/cshader, for Shader Loading
    https://github.com/MousieDev, for all the tips and helping me with the Engine

# Codebase:
    github.com/AlDanial/cloc v 1.90  T=0.21 s (196.0 files/s, 242095.7 lines/s)
    -------------------------------------------------------------------------------
    Language                     files          blank        comment           code
    -------------------------------------------------------------------------------
    C/C++ Header                    19           2675           6902          30202
    C                                5            110              4          10244
    Markdown                         1             65              0            151
    GLSL                            10             51              1            100
    Bourne Shell                     2             15              0             66
    make                             2             8              1             17
    YAML                             1              6              1             13
    DOS Batch                        1              4              0              7
    -------------------------------------------------------------------------------
    SUM:                            41           2934           6909          40800
    ------------------------------------------------------------------------------- 
