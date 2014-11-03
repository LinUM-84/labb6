
// Module calculates heat effect from resistance
//dependent on math.h 

// P = power
// U = volt
// I = Current
// R = rstance

//P = U²/R  
float calc_power_r(float volt, float resistance)
{
  return pow(volt, 2) / resistance; 
}

// P = U * I // 
float calc_power_i(float volt, float current)
{
  return volt * current; 
} 
