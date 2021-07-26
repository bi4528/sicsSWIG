# Integration of Subgraph Isomorphism Constraint Satisfaction library written in C++ into Java using JNI and SWIG
An executable example for using [Subgraph Isomorphism Constraint Satisfaction library](https://git.sr.ht/~xnevs/sics) in Java 

# Requirements
At this moment it is supported on Windows 10.

[JAVA SE 14](https://www.oracle.com/java/technologies/javase/jdk14-archive-downloads.html) is required.

[SWIG for Windows](http://www.swig.org/Doc1.3/Windows.html) is required.

# Installing the project
Download the project from the [sicsSWIG](https://github.com/bi4528/sicsSWIG)

## Using Eclipse
- **File->Import->Project from Folder or Archive** browse the Archive project and select **Finish**
- Find the project in **Project Explorer** and select **Run Configurations**
- In **Run Configurations** **Project** should be **sicsSWIG** and **Main class**: **runme**
- **Apply** and **Run** the project

# Usage
In the example it is clear that class which has to be executed (int this case **runme**) requires:

    static {
	    try {
	        System.loadLibrary("sicsSWIG");
	    } catch (UnsatisfiedLinkError e) {
	      System.err.println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n" + e);
	      System.exit(1);
	    }
	  }
    
where *sicsSWIG* is the name of the library with *.dll* extension.

The library currently supports two classes `SicsAlgorithams_AdjListMat_Bidirected` and `SicsAlgorithams_AdjListMat_Undirected` which are used for executing algorithms 
on two graphs (currently *bidirected* and *undirected* saved in adjecancy list and matrix). 

An example of initializing two graphs:

    SicsAlgorithams_AdjListMat_Bidirected sics = new SicsAlgorithams_AdjListMat_Bidirected(3, 4);
    
where 3 is number of verteces of the first graph and 4 is number of verteces of the second graph.

For setting a vertex lable of the first graph use `sics.set_vertex_label_graph_1(0, "red");`, whereas for the second graph  `sics.set_vertex_label_graph_2(0, "red");`

For adding an edge between two verteces of the first graph use `sics.add_edge_graph_1(0, 1);`, whereas for the second graph  `sics.add_edge_graph_2(1, 2);`

For executing the algorithms from [Subgraph Isomorphism Constraint Satisfaction library](https://git.sr.ht/~xnevs/sics) use:

    sics.backjumping_degreeprune_ind("DEG");
    
where instead of "DEG" can be also use "RDEG" or "GCF".
 ## Result
     0 -> 0
     1 -> 1
     2 -> 2

     0 -> 0
     1 -> 1
     2 -> 3

     2
where the first lines presents isomorphisms and the last line the number of them.
