
public class runme{
	
	static {
	    try {
	        System.loadLibrary("sicsSWIG");
	    } catch (UnsatisfiedLinkError e) {
	      System.err.println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n" + e);
	      System.exit(1);
	    }
	  }

	public static void main(String[] args) {
		
		SicsAlgorithams_AdjListMat_Bidirected sics = new SicsAlgorithams_AdjListMat_Bidirected(3, 4);
		
		sics.set_vertex_label_graph_1(0, "red");
		sics.set_vertex_label_graph_1(1, "blue");
		sics.set_vertex_label_graph_1(2, "green");
		sics.add_edge_graph_1(0, 1);
		sics.add_edge_graph_1(1, 2);
		sics.add_edge_graph_1(2, 0);
		
		sics.set_vertex_label_graph_2(0, "red");
		sics.set_vertex_label_graph_2(1, "blue");
		sics.set_vertex_label_graph_2(2, "green");
		sics.set_vertex_label_graph_2(3, "green");
		sics.add_edge_graph_2(0, 1);
		sics.add_edge_graph_2(1, 2);
		sics.add_edge_graph_2(2, 0);
		sics.add_edge_graph_2(1, 3);
		sics.add_edge_graph_2(3, 0);
		
		sics.backjumping_degreeprune_ind("DEG");
		
	}

}
