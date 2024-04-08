# CPP_CellularAutomata_stage1
  Using OpenGL, this works as a project creating a 2d array of Cell* objects in which simulate state of a cell. Using the traditional game of life ruleset to turn on and off, this program will spark a small subset of the 260x260 2d array to "give life" to the simulation and start the reactions. This will go rouge and doesn't have a real way to terminate.

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/a75aa857-8712-426d-8da4-110db742dffd" alt="Cornstarch <3" width="115" height="89">

  I made this project as a knowledge check for myself in understanding OpenGL from my initial knowledge of the subject using my 3D worldspace engine in my previous repo. Gave me firmer understanding of buffer handling as well as shader handling.

  Very rough prog, I'm going to be slowly building upon a single file in order to build more elaborate cellular automata so am using this repo as a quick file dump.


------------------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/0e0f4579-756c-4805-8730-9508018bed9b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/0e0f4579-756c-4805-8730-9508018bed9b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/0e0f4579-756c-4805-8730-9508018bed9b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/0e0f4579-756c-4805-8730-9508018bed9b" alt="Cornstarch <3" width="55" height="49">



**The Breakdown:**

  This Program Works With GLSL And OpenGL In Order To Make A Window And Draw To It In Order To Demonstrate The Basic Concept Of Conway's Game Of Life. 

  In Order To Demonstrate The Game Of Life We Initialize A 2D Array Of Equally-Sized Cubes. The Cubes Will Be Represented In The Window By Given Coordinates In The Window. Using A Algorithm, We Will Place A Specified Constant Amount Of Cells In A 2D-World Map For Our Cubes. These Cubes Will Represent A Given Cell. The Cubes Are Then Wrapped In Their Own Class In Which Represents Its Vertexes Buffer Offset As Well As Alive State And Its Adjacent Neighbors.

  Because Our Scene Format Will Be Quite Constant Throughout And Only Represents Squares We Can Use Only Our Offset And Still Call Our Vertex Buffer To Change Our Specified Vertexes That Represent Our Given Cell.

  Other Than General Drawing Functionality, We Also Include A React function In Which Is Called Every Main Game Loop Tick. In This Reaction Function Is Where We See The Game Of Life Being Applied.

  Conway's Game Of Life Works On The Concept Of A Cell (Or Given Cube) Reacting Based Upon Its Neighbors Current States. In This Iteration Of The Game We First Count Up The Amount Of Our Neighbors In Which Are Alive, The After Getting This Total We Do The Following:

  &nbsp;- If We Are Alive: If We Have Either 3, Or 2 Alive Neighbors We Die From Overpopulation.

  &nbsp;- If We Are Dead: If We Have 3 Alive Neighbors, Become Alive From Reproduction.


  In Order To Apply This Properly We Will Index Through Our 2D Array Of Cubes/Cells And Call Their React Function. By Constantly Calling This react Function We Simulate Evolution Of Our Cells As Each Cell In The 2D-Array Is Updated By Reference Every react Tick.

  This Program Taught Me A Lot About Buffer Optimizations By Laying Out Data Properly And Utilizing This Layout To Work With Offsets For Quick Accessing In A Variable Size Stream Of Data. This Program Also Greatly Helped Me Understand Better Data Handling And Proper Class Encapsulation. Another Big Thing Understood With This Project Was Compounding Problems As In This Program, Because We Are Indexing A 2D Array IN PLACE It Means We Will Change A State When We Are Done With It Directly In Our Map Without A Update Buffer. This Means If We Want To Simulate Independent Movements That Dont Move "Down-The-Line" We Must Include Special Flags When A Cell Grows Up to Ensure That That Cell That Grew Upwards Doesn't Get Called Again When We Go To The Next Row Of Our 2D-Cells As Then We Will Call This Cell Again, Moving It Up. This Can Cause A Single "Cell/Block" To Move 2 Times When They Should Be Moving Only Once Per Cycle Of The 2D-Array.

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/b1acfe27-bfee-4250-9b6f-f761371ddf3e" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/b1acfe27-bfee-4250-9b6f-f761371ddf3e" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/b1acfe27-bfee-4250-9b6f-f761371ddf3e" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/b1acfe27-bfee-4250-9b6f-f761371ddf3e" alt="Cornstarch <3" width="55" height="49"> 




------------------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/4248d78b-b941-477c-b50e-3e6b0a3d9028" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/4248d78b-b941-477c-b50e-3e6b0a3d9028" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/4248d78b-b941-477c-b50e-3e6b0a3d9028" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/4248d78b-b941-477c-b50e-3e6b0a3d9028" alt="Cornstarch <3" width="55" height="49">


**Features:**


![2024-01-1717-56-12-ezgif com-video-to-gif-converter](https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/3457ef03-4667-4dbe-9bbb-49bb638f4f04)



<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/ac268977-c7dc-46d6-8dab-be0424773c4d" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/ac268977-c7dc-46d6-8dab-be0424773c4d" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/ac268977-c7dc-46d6-8dab-be0424773c4d" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_stage1/assets/76754592/ac268977-c7dc-46d6-8dab-be0424773c4d" alt="Cornstarch <3" width="55" height="49">
