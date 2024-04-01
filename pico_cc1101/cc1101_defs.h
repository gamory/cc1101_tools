// This contains a bunch of helpful defines specific to the CC1101 controller.  It *may* be consistent with other similar models, but I make no promises

// Register locations

#define CC1101_IOCFG2 0x00 // IOCFG2 register location, GDO2 Output Pin Configuration
#define CC1101_IOCFG1 0x01 // IOCFG1 register location, GDO1 Output Pin Configuration
#define CC1101_IOCFG0 0x02 // IOCFG0 register location, GDO0 Output Pin Configuration
#define CC1101_FIFOTHR 0x03 // FIFOTHR register location, RX FIFO and TX FIFO Thresholds
#define CC1101_SYNC1 0x04 // SYNC1 register location, Sync Word, High Byte
#define CC1101_SYNC0 0x05 // SYNC0 register location, Sync Word, Low Byte
#define CC1101_PKTLEN 0x06 // PKTLEN register location, Packet Length
#define CC1101_PKTCTRL1 0x07 // PKTCTRL1 register location, Packet Automation Control
#define CC1101_PKTCTRL0 0x08 // PKTCTRL0 register location, Packet Automation Control
#define CC1101_ADDR 0x09 // ADDR register location, Device Address
#define CC1101_CHANNR 0x0A // CHANNR register location, Channel Number
#define CC1101_FSCTRL1 0x0B // FSCTRL1 register location, Frequency Synthesizer Control
#define CC1101_FSCTRL0 0x0C // FSCTRL0 register location, Frequency Synthesizer Control
#define CC1101_FREQ2 0x0D // FREQ2 register location, Frequency Control Word, High Byte
#define CC1101_FREQ1 0x0E // FREQ1 register location, Frequency Control Word, Middle Byte
#define CC1101_FREQ0 0x0F // FREQ0 register location, Frequency Control Word, Low Byte
#define CC1101_MDMCFG4 0x10 // MDMCFG4 register location, Modem Configuration
#define CC1101_MDMCFG3 0x11 // MDMCFG3 register location, Modem Configuration
#define CC1101_MDMCFG2 0x12 // MDMCFG2 register location, Modem Configuration
#define CC1101_MDMCFG1 0x13 // MDMCFG1 register location, Modem Configuration
#define CC1101_MDMCFG0 0x14 // MDMCFG0 register location, Modem Configuration
#define CC1101_DEVIATN 0x15 // DEVIATN register location, Modem Deviation Setting
#define CC1101_MCSM2 0x16 // MCSM2 register location, Main Radio Control State Machine Configuration
#define CC1101_MCSM1 0x17 // MCSM1 register location, Main Radio Control State Machine Configuration
#define CC1101_MCSM0 0x18 // MCSM0 register location, Main Radio Control State Machine Configuration
#define CC1101_FOCCFG 0x19 // FOCCFG register location, Frequency Offset Compensation Configuration
#define CC1101_BSCFG 0x1A // BSCFG register location, Bit Synchronization Configuration
#define CC1101_AGCCTRL2 0x1B // AGCCTRL2 register location, AGC Control
#define CC1101_AGCCTRL1 0x1C // AGCCTRL1 register location, AGC Control
#define CC1101_AGCCTRL0 0x1D // AGCCTRL0 register location, AGC Control
#define CC1101_WOREVT1 0x1E // WOREVT1 register location, High Byte Event0 Timeout
#define CC1101_WOREVT0 0x1F // WOREVT0 register location, Low Byte Event0 Timeout
#define CC1101_WORCTRL 0x20 // WORCTRL register location, Wake On Radio Control
#define CC1101_FREND1 0x21 // FREND1 register location, Front End RX Configuration
#define CC1101_FREND0 0x22 // FREND0 register location, Front End TX Configuration
#define CC1101_FSCAL3 0x23 // FSCAL3 register location, Frequency Synthesizer Calibration
#define CC1101_FSCAL2 0x24 // FSCAL2 register location, Frequency Synthesizer Calibration
#define CC1101_FSCAL1 0x25 // FSCAL1 register location, Frequency Synthesizer Calibration
#define CC1101_FSCAL0 0x26 // FSCAL0 register location, Frequency Synthesizer Calibration
#define CC1101_RCCTRL1 0x27 // RCCTRL1 register location, RC Oscillator Configuration
#define CC1101_RCCTRL0 0x28 // RCCTRL0 register location, RC Oscillator Configuration
#define CC1101_FSTEST 0x29 // FSTEST register location, Frequency Synthesizer Calibration Control
#define CC1101_PTEST 0x2A // PTEST register location, Production Test
#define CC1101_AGCTEST 0x2B // AGCTEST register location, AGC Test
#define CC1101_TEST2 0x2C // TEST2 register location, Various Test Settings
#define CC1101_TEST1 0x2D // TEST1 register location, Various Test Settings
#define CC1101_TEST0 0x2E // TEST0 register location, Various Test Settings
#define CC1101_PARTNUM 0x30 // PARTNUM register location, Chip ID, R/O
#define CC1101_VERSION 0x31 // VERSION register location, Chip ID, R/O
#define CC1101_FREQEST 0x32 // FREQEST register location, Frequency Offset Estimate from Demodulator, R/O
#define CC1101_LQI 0x33 // LQI register location, Demodulator Estimate for Link Quality, R/O
#define CC1101_RSSI 0x34 // RSSI register location, Received Signal Strength Indication, R/O
#define CC1101_MARCSTATE 0x35 // MARCSTATE register location, Main Radio Control State Machine State, R/O
#define CC1101_WORTIME1 0x36 // WORTIME1 register location, High Byte of WOR Time, R/O
#define CC1101_WORTIME0 0x37 // WORTIME0 register location, Low Byte of WOR Time, R/O
#define CC1101_PKTSTATUS 0x38 // PKTSTATUS register location, Current GDOx Status and Packet Status, R/O
#define CC1101_VCO_VC_DAC 0x39 // VCO_VC_DAC register location, Current Setting from PLL Calibration Module, R/O
#define CC1101_TXBYTES 0x3A // TXBYTES register location, Underflow and Number of Bytes, R/O
#define CC1101_RXBYTES 0x3B // RXBYTES register location, Overflow and Number of Bytes, R/O
#define CC1101_RCCTRL1_STATUS 0x3C // RCCTRL1_STATUS register location, Last RC Oscillator Calibration Result, R/O
#define CC1101_RCCTRL0_STATUS 0x3D // RCCTRL0_STATUS register location, Last RC Oscillator Calibration Result, R/O