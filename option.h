#ifndef OPTION_H
#define OPTION_H


class Option
{
    public:
        /** Default constructor */
        Option(double S; double K; double σ; int t; int T; double r);
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

        /** Access τ
         * \return The current value of τ
         */
        int Getτ() { return τ; }
        /** Set τ
         * \param val New value to set
         */
        void Setτ(int val) { τ = val; }
        /** Access r
         * \return The current value of r
         */
        double Getr() { return r; }
        /** Set r
         * \param val New value to set
         */
        void Setr(double val) { r = val; }
        /** Access S
         * \return The current value of S
         */
        double GetS() { return S; }
        /** Set S
         * \param val New value to set
         */
        void SetS(double val) { S = val; }
        /** Access K
         * \return The current value of K
         */
        double GetK() { return K; }
        /** Set K
         * \param val New value to set
         */
        void SetK(double val) { K = val; }
        /** Access σ
         * \return The current value of σ
         */
        double Getσ() { return σ; }
        /** Set σ
         * \param val New value to set
         */
        void Setσ(double val) { σ = val; }
        /** Access t
         * \return The current value of t
         */
        int Gett() { return t; }
        /** Set t
         * \param val New value to set
         */
        void Sett(int val) { t = val; }
        /** Access T
         * \return The current value of T
         */
        int GetT() { return T; }
        /** Set T
         * \param val New value to set
         */
        void SetT(int val) { T = val; }

    protected:

    private:
        double r; //!< Member variable "r"
        double S; //!< Member variable "S"
        double K; //!< Member variable "K"
        double σ; //!< Member variable "σ"
        int t; //!< Member variable "t"
        int T; //!< Member variable "T"
        int τ = T - t; //!< Member variable "τ"
};

#endif // OPTION_H
