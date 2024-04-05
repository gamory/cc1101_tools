#include <cstdint>
#include <sstream>
#include <iomanip>

void get_frequency_values(uint32_t freq_xtal, uint32_t freq_hz, uint32_t* FREQ2, uint32_t* FREQ1, uint32_t* FREQ0) {
    uint64_t res;
    res=((uint64_t) freq_hz * (uint64_t) (1<<16)) / ((uint64_t) freq_xtal);
    std::stringstream ss;
    std::string fullreg;
    ss << std::setw(6) << std::setfill('0') << std::hex << res;
    fullreg = ss.str();
    *FREQ2 = (uint32_t)std::stoul(fullreg.substr(0,2),nullptr,16);
    *FREQ1 = (uint32_t)std::stoul(fullreg.substr(2,2),nullptr,16);
    *FREQ0 = (uint32_t)std::stoul(fullreg.substr(4,2),nullptr,16);
    return;
}
