#include <cstdint>

#include <fstream>
#include <iostream>
#include <string>

#include <adjacency_listmat.h>
#include <vertex_order.h>
#include <adjacency_listmat.h>
#include <adjacency_list.h>
#include <adjacency_degreesortedlistmat.h>
#include <vertex_order.h>
#include <lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind.h>
#include <backjumping_bitset_degreeprune_ind.h>
#include <backjumping_bitset_degreesequenceprune_ind.h>
#include <backjumping_degreeprune_ind.h>
#include <backjumping_degreesequenceprune_ind.h>
#include <backjumping_ind.h>
#include <backtracking_adjacentconsistency_forwardcount_ind.h>
#include <backtracking_adjacentconsistency_ind.h>
#include <backtracking_adjacentconsistency_precount_ind.h>
#include <backtracking_bitset_degreeprune_ind.h>
#include <backtracking_bitset_degreesequenceprune_ind.h>
#include <backtracking_degreeprune_adjacentconsistency_forwardcount_ind.h>
#include <backtracking_degreeprune_adjacentconsistency_ind.h>
#include <backtracking_degreeprune_adjacentconsistency_precount_ind.h>
#include <backtracking_degreeprune_ind.h>
#include <backtracking_degreesequenceprune_ind.h>
#include <backtracking_forwardcount_ind.h>
#include <backtracking_ind.h>
#include <backtracking_parent_adjacentconsistency_forwardcount_ind.h>
#include <backtracking_parent_adjacentconsistency_ind.h>
#include <backtracking_parent_adjacentconsistency_precount_ind.h>
#include <backtracking_parent_degreeprune_adjacentconsistency_forwardcount_ind.h>
#include <backtracking_parent_degreeprune_adjacentconsistency_ind.h>
#include <backtracking_parent_degreeprune_adjacentconsistency_precount_ind.h>
#include <backtracking_parent_degreeprune_ind.h>
#include <backtracking_parent_forwardcount_ind.h>
#include <backtracking_parent_ind.h>
#include <conflictbackjumping_degreeprune_ind.h>
#include <conflictbackjumping_degreesequenceprune_ind.h>
#include <conflictbackjumping_ind.h>
#include <forwardchecking_bitset_degreeprune_ac1_ind.h>
#include <forwardchecking_bitset_degreeprune_countingalldifferent_ind.h>
#include <forwardchecking_bitset_degreeprune_ind.h>
#include <forwardchecking_bitset_degreesequenceprune_ac1_ind.h>
#include <forwardchecking_bitset_degreesequenceprune_countingalldifferent_ind.h>
#include <forwardchecking_bitset_degreesequenceprune_ind.h>
#include <forwardchecking_bitset_mrv_degreeprune_ac1_ind.h>
#include <forwardchecking_bitset_mrv_degreeprune_countingalldifferent_ind.h>
#include <forwardchecking_bitset_mrv_degreeprune_ind.h>
#include <forwardchecking_bitset_mrv_degreesequenceprune_ac1_ind.h>
#include <forwardchecking_bitset_mrv_degreesequenceprune_countingalldifferent_ind.h>
#include <forwardchecking_bitset_mrv_degreesequenceprune_ind.h>
#include <forwardchecking_degreeprune_ind.h>
#include <forwardchecking_degreesequenceprune_ind.h>
#include <forwardchecking_ind.h>
#include <forwardchecking_mrv_degreeprune_ind.h>
#include <lazyforwardchecking_degreeprune_ind.h>
#include <lazyforwardchecking_degreesequenceprune_ind.h>
#include <lazyforwardchecking_ind.h>
#include <lazyforwardchecking_low_bitset_degreeprune_ind.h>
#include <lazyforwardchecking_low_bitset_degreesequenceprune_ind.h>
#include <lazyforwardchecking_low_degreeprune_ind.h>
#include <lazyforwardchecking_low_degreesequenceprune_ind.h>
#include <lazyforwardchecking_low_ind.h>
#include <lazyforwardchecking_low_parent_degreeprune_ind.h>
#include <lazyforwardchecking_low_parent_ind.h>
#include <lazyforwardchecking_parent_degreeprune_ind.h>
#include <lazyforwardchecking_parent_degreesequenceprune_ind.h>
#include <lazyforwardchecking_parent_ind.h>
#include <lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind.h>
#include <lazyforwardcheckingbackjumping_low_bitset_degreesequenceprune_ind.h>

using graph_type = sics::adjacency_listmat<uint16_t, sics::directed_tag, std::string>;

class SicsAlgorithams_AdjListMat_Directed {
    graph_type graph_1;
    graph_type graph_2;
public:
    SicsAlgorithams_AdjListMat_Directed(int num_g, int num_h) : graph_1(num_g), graph_2(num_h) {};
    
    void set_vertex_label_graph_1(int v, std::string c) {
        graph_1.set_vertex_label(v, c);
    };
    void  add_edge_graph_1(int v1, int v2) {
        graph_1.add_edge(v1, v2);
    };
    
    void set_vertex_label_graph_2(int v, std::string c) {
        graph_2.set_vertex_label(v, c);
    };
    void  add_edge_graph_2(int v1, int v2) {
        graph_2.add_edge(v1, v2);
    };

    void backjumping_bitset_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backjumping_bitset_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backjumping_bitset_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backjumping_bitset_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backjumping_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backjumping_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backjumping_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backjumping_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backjumping_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backjumping_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_adjacentconsistency_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_adjacentconsistency_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_adjacentconsistency_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_adjacentconsistency_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_adjacentconsistency_precount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_adjacentconsistency_precount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_bitset_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_bitset_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_bitset_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_bitset_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_degreeprune_adjacentconsistency_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_degreeprune_adjacentconsistency_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_degreeprune_adjacentconsistency_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_degreeprune_adjacentconsistency_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_degreeprune_adjacentconsistency_precount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_degreeprune_adjacentconsistency_precount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    /*void backtracking_parent_adjacentconsistency_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_adjacentconsistency_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_adjacentconsistency_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_adjacentconsistency_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_adjacentconsistency_precount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_adjacentconsistency_precount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_degreeprune_adjacentconsistency_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_degreeprune_adjacentconsistency_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_degreeprune_adjacentconsistency_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_degreeprune_adjacentconsistency_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_degreeprune_adjacentconsistency_precount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_degreeprune_adjacentconsistency_precount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_forwardcount_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_forwardcount_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void backtracking_parent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::backtracking_parent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };*/

    void conflictbackjumping_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::conflictbackjumping_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void conflictbackjumping_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::conflictbackjumping_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void conflictbackjumping_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::conflictbackjumping_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreeprune_ac1_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreeprune_ac1_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreeprune_countingalldifferent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreeprune_countingalldifferent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreesequenceprune_ac1_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreesequenceprune_ac1_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreesequenceprune_countingalldifferent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreesequenceprune_countingalldifferent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    /*void forwardchecking_bitset_mrv_degreeprune_ac1_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreeprune_ac1_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_mrv_degreeprune_countingalldifferent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreeprune_countingalldifferent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_mrv_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_mrv_degreesequenceprune_ac1_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreesequenceprune_ac1_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_mrv_degreesequenceprune_countingalldifferent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreesequenceprune_countingalldifferent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_bitset_mrv_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_bitset_mrv_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };*/

    void forwardchecking_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void forwardchecking_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    /*void forwardchecking_mrv_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::forwardchecking_mrv_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };*/

    void lazyforwardchecking_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_bitset_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_bitset_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_bitset_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_bitset_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    /*void lazyforwardchecking_low_parent_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_parent_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_low_parent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_low_parent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_parent_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_parent_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_parent_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_parent_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardchecking_parent_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardchecking_parent_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };*/

    void lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardcheckingbackjumping_low_bitset_degreeprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };

    void lazyforwardcheckingbackjumping_low_bitset_degreesequenceprune_ind(std::string v_order) {

        int count = 0;
        auto index_order_graph_1 = sics::vertex_order_GreatestConstraintFirst(graph_1);

        if (v_order == "DEG") {
            index_order_graph_1 = sics::vertex_order_DEG(graph_1);
        }
        else if (v_order == "RDEG") {
            index_order_graph_1 = sics::vertex_order_RDEG(graph_1);
        }

        sics::lazyforwardcheckingbackjumping_low_bitset_degreesequenceprune_ind(
            graph_1,
            graph_2,
            [&count](auto const& S) {
                ++count;
                for (int i = 0; i < S.map.size(); ++i) {
                    std::cout << i << " -> " << S.map[i] << std::endl;
                }
                std::cout << std::endl;
                return true;
            },
            index_order_graph_1);

        std::cout << count << std::endl;
    };
};