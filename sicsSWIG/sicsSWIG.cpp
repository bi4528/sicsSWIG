#include <cstdint>

#include <fstream>
#include <iostream>
#include <string>

#include <adjacency_listmat.h>
#include <vertex_order.h>
#include <lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind.h>

using graph_type = sics::adjacency_listmat<uint16_t, sics::bidirectional_tag, std::string>;

void lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind() {
  
  graph_type g(3);
  g.set_vertex_label(0, "red");
  g.set_vertex_label(1, "blue");
  g.set_vertex_label(2, "green");
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 0);

  graph_type h(4);
  h.set_vertex_label(0, "red");
  h.set_vertex_label(1, "blue");
  h.set_vertex_label(2, "green");
  h.set_vertex_label(3, "green");
  h.add_edge(0, 1);
  h.add_edge(1, 2);
  h.add_edge(2, 0);
  h.add_edge(1, 3);
  h.add_edge(3, 0);

  int count = 0;
  auto index_order_g = sics::vertex_order_GreatestConstraintFirst(g);
  sics::lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind(
      g,
      h,
      [&count](auto const & S) {
        ++count;
        for (int i=0; i<S.map.size(); ++i) {
          std::cout << i << " -> " << S.map[i] << std::endl;
        }
        std::cout << std::endl;
        return true;
      },
      index_order_g);

  std::cout << count << std::endl;
}
