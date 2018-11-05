/* This is the psuedo code we brought up on 11/15/2018
 * Debris:
 * Output pin high at a timed interval 
 * possibly need to be over haystack 
 * if timer alone, can we do based off GPS sensor time?
 * gps doesn't fit in 1T
 *
 * Pyrolysis: 
 * Take in from RGB sensor and IR sensor
 * RGB currently requires i2C
 * based off a specific time (GPS input again?)
 * package this information for the transmission to upland
 * put into histogram format
 *
 * Logical background: 
 * Handle start up
 * check battery power 
 * read from RX
 * handle tx?
 * alive status signal at burt 
 * */
