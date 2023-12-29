#ifndef OPTION_H
#define OPTION_H
using namespace std;

class Option
{

protected:
    double r; //!< Member variable "r : risk-free rate"
    double S; //!< Member variable "S : Stock price of the underlying asset at time t"
    double K; //!< Member variable "K : Strike price of the option"
    double v; //!< Member variable "v : volatility"
    double t; //!< Member variable "t : time t"
    double T; //!< Member variable "T : maturity date"
    double tenor; //!< Member variable "tenor"
    double d1;
    double delta;
    string option_type;

public:
    /** Default constructor **/
    Option();
    /** Parameters constructor **/
    Option(double S, double K, double v, double t, double T, double r);
    /** Default destructor */
    virtual ~Option();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Option(Option& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Option& operator=(Option& other);

    /** Access tenor
     * \return The current value of tenor
     */
    double Gettenor()
    {
        return tenor;
    }
    /** Set tenor
     * \param val New value to set
     */
    void Settenor()
    {
        tenor = T - t;
    }
    /** Set d1
     * Actualize d1 value
     */
    void Setd1()
    {
        d1 = (log(S/K) + (r + v*v / 2)*tenor) / (v * sqrt(tenor));
    }
    /** Access r
     * \return The current value of r
     */
    double Getr()
    {
        return r;
    }
    /** Set r
     * \param val New value to set
     */
    void Setr(double val)
    {
        r = val;
    }
    /** Access S
     * \return The current value of S
     */
    double GetS()
    {
        return S;
    }
    /** Set S
     * \param val New value to set
     */
    void SetS(double val)
    {
        S = val;
    }
    /** Access K
     * \return The current value of K
     */
    double GetK()
    {
        return K;
    }
    /** Set K
     * \param val New value to set
     */
    void SetK(double val)
    {
        K = val;
    }
    /** Access v
     * \return The current value of v
     */
    double Getv()
    {
        return v;
    }
    /** Set v
     * \param val New value to set
     */
    void Setv(double val)
    {
        v = val;
    }
    /** Access t
     * \return The current value of t
     */
    double Gett()
    {
        return t;
    }
    /** Set t
     * \param val New value to set
     */
    void Sett(int val)
    {
        t = val;
    }
    /** Access T
     * \return The current value of T
     */
    double GetT()
    {
        return T;
    }
    /** Set T
     * \param val New value to set
     */
    void SetT(int val)
    {
        T = val;
    }

    /** Access option_type
     * \return The current value of option_type
     */
    string Getoption_type()
    {
        return option_type;
    }
    /** Set option_type
     * \param val New value to set
     */
    void Setoption_type(string val)
    {
        option_type = val;
    }

    /** Set delta : actualize delta value **/

    virtual void Setdelta(){};

    /** Get Black-Scholes theorical option's price **/

    virtual double price()
    {
        return 0;
    };

    /** Calculate payoff for a call **/

    virtual double payoff(double Z)
    {
        return 0;
    };

    /** Monte Carlo Method that involves in calculating the empiric mean of discounted payoff for t=T **/
    double MonteCarloSimulation(int N, bool verbose);

    /** Process trajectory of S_t under BSM assumptions with a step of s and for N values **/
    double* underlying_trajectory(double s, int N);

    /** Process trajectory of option's delta with a step of s and for N values **/
    double* delta_trajectory(double s, int N);

};


class Call : public Option
{
public:
    /** Default constructor **/
    Call() : Option()
    {
        option_type = "call";
        delta = normalCDF(d1);
    } ;
    /** Parameters constructor **/
    Call(double S, double K, double v, double t, double T, double r) : Option(S,K,v,t,T,r)
    {
        option_type = "call";
        delta = normalCDF(d1);
    };
    /** Copy constructor **/
    Call(Option& other) : Option(other)
    {
        option_type = "call";
        delta = normalCDF(d1);
    };
    /** Default destructor */
    virtual ~Call();
    /** Setting delta with BSM model **/
    virtual void Setdelta();
    /** Get Black-Scholes theorical call price **/
    virtual double price();
    /** Calculate payoff for a call **/
    virtual double payoff(double Z);
};

class Put : public Option
{
public:
    /** Default constructor **/
    Put() : Option()
    {
        option_type = "put";
        delta = normalCDF(d1) - 1;
    } ;
    /** Parameters constructor **/
    Put(double S, double K, double v, double t, double T, double r) : Option(S,K,v,t,T,r)
    {
        option_type = "put";
        delta = normalCDF(d1) - 1;
    };
    /** Copy constructor **/
    Put(Option& other) : Option(other)
    {
        option_type = "put";
        delta = normalCDF(d1) - 1;
    };
    /** Default destructor **/
    virtual ~Put();
    /** Setting delta with BSM model **/
    virtual void Setdelta();
    /** Get Black-Scholes theorical put price **/
    virtual double price();
    /** Calculate payoff for a call **/
    virtual double payoff(double Z);
};

ostream& operator<<(ostream& os, Option& option);

#endif // OPTION_H
