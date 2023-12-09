#include "include/functions.h"
#include <cstdint>
#include <vector>
#include <numeric>

namespace func {
    uint64_t diagonal_spiral_sum(uint64_t side_length_limit) {
        uint64_t prior_sub_seg_end_val = 1;
        uint64_t diagonal_sum_tot = 1;
        
        for (uint64_t side_len = 3; side_len <= side_length_limit; side_len += 2) {
            std::vector<uint64_t> sub_seg_list;
            for (unsigned int i = 0; i < 4; i++) {
                if (i == 0) {
                    sub_seg_list.push_back(prior_sub_seg_end_val + (side_len - 1));
                } else {
                    sub_seg_list.push_back(sub_seg_list[i - 1] + (side_len - 1));
                }
            }

            prior_sub_seg_end_val = sub_seg_list.back();
            diagonal_sum_tot += std::reduce(sub_seg_list.begin(), sub_seg_list.end());
        }

        return diagonal_sum_tot;
    }
}