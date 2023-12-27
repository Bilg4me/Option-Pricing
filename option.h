#ifndef OPTION_H
#define OPTION_H

class Option
{
public:
    /** Default constructor **/
    Option(double S, double K, double v, int t, int T, double r);
    /** Default destructor */
    virtual ~Option();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Option(const Option& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Option& operator=(const Option& other);

    /** Access tenor
     * \return The current value of tenor
     */
    int Gettenor()
    {
        return tenor;
    }
    /** Set tenor
     * \param val New value to set
     */
    void Settenor(int val)
    {
        tenor = val;
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
    int Gett()
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
    int GetT()
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

protected:

private:
    double r; //!< Member variable "r"
    double S; //!< Member variable "S"
    double K; //!< Member variable "K"
    double v; //!< Member variable "v"
    int t; //!< Member variable "t"
    int T; //!< Member variable "T"
    int tenor = T - t; //!< Member variable "tenor"
};

#endif // OPTION_H
