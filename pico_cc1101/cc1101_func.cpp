#include <cstdint>

uint32_t get_frequency_values(uint32_t freq_xtal, uint32_t freq_hz) {
    uint64_t res;
    res=((uint64_t) freq_hz * (uint64_t) (1<<16)) / ((uint64_t) freq_xtal);
    return(uint32_t) res;
}
