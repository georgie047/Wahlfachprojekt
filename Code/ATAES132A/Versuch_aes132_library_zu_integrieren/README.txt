Created By: Gilang

--- STATUS ---

15 June 2015
Serial debug added. Bug on parser stil exist

18 June 2015
Bug on parser fixed

---HOW TO USE---
1. Connect SAMD21 to Notebook/PC
2. Open Putty or other Serial Terminal Application
3. Connect Serial Terminal Application to SAMD21 EDBG port.
4. Use below input for testing:
* Function test:
(80): Write Memory
(81): Read Memory
(82): BlockRead

Parser Test;
(10 00 00 00 00 04): Block Read 4 bytes to address 0x00 00 
(0C 00 00 06 00 00): Info Command to read DeviceNum
