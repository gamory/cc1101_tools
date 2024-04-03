// This almost certainly needs work, there probably isn't a 64 bit int in this platform
// I got this off the internet, and will need to figure out how to make it work.

/*
uint8_t get_frequency_values(uint32_t freq_xtal, uint32_t freq_hz) {
    uint64_t res;
    res=((uint64_t) freq_hz * (uint64_t) (1<<16)) / ((uint64_t) freq_xtal);
    return(uint32_t) res;
}
*/
int get_frequency_values(int freq_xtal, int freq_hz) {
    int res;
    res=((int) freq_hz * (int) (1<<16)) / ((int) freq_xtal);
    return(int) res;
}