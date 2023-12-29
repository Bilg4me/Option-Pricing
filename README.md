# Option Pricing
 Monte Carlo Option Pricing Project @ENSAE


Explanation of what the code does :


To begin with, we recall that this project has for purpose to determine the price of a random European vanilla option (Call and Put), with their replication strategy by using Monte-Carlo Method and Simulations.

Therefore in the end, we will have at each time t smaller than the maturity T of the option : 

- The price of the option
- The payoff of the option
- The delta of the option

We will be able to get the put informations if we have already calculated a call and get the call informations if we have already calculated the put with the same parameters.

So, to get all these informations with Monte-Carlo Method, we have to implement some functions to get a brownian path.

In order to get a brownian path, we implemented few functions :

- a standard normal distribution 'standard_normal_dist' that creates a N-array of values following a N(0,1)

- the function 'BM' that takes an N-array from 'standard_normal_dist' and transforms it into a Brownian Motion with a time step s and N values.

Now we can create a Brownian Motion easily with these function. 

With this 'normal' brownian motion, we will create a new brownian motion that will have for parameters the risk-free rate, the volatility, the initial price of the underlying asset in order to simulate a potential path for the future price of the underlying asset. Function : 'underlying_trajectory'

The simulation of Monte-Carlo consists in the simulation of a lot of these paths for the underlying trajectory, then we will take the mean for each time step of the price value of all the trajectory in order to get a 'mean' trajectory that should in theory tend to the real future trajectory of the underlying asset according to the law of large number.

So, we created 'MonteCarloSimulation' that takes the mean of all payoff (and not trajectory), and with a discounting term, we get the present value of the mean payoff for each time step t.

With the 'delta_trajectory' function, we can get the trajectory in the time of the delta by differentiating the value of the option by the price of the underlying asset. We simply do the ratio of the variation of the price of the option between two time step over the variation of the price of the underlying asset between two time step.

Moreover, in order to be sure that our values are near from the reality (from the theory here), we implemented the CDF of the normal distribution and, according to the formulas of the Black-Scholes Models, we implemented price() and Setdelta for both call and put, that gives the theoric price of the option and its delta.










What we could optimize or where we could go further on this code :

We could have tried to compare our code with some realistic european option values on the stock markets. We could have made a code to implement the implicit volatility and use it to determine option price by ourselves and compare with the stock values. We could also implement a code that gives historic values of the volatility, by doing a regression on the log-values of the price of the underlying asset on the time.