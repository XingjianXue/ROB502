#include <iostream>
#include <initializer_list>
#include <vector>
// needed for setting printing precision
#include <iomanip>
#include <sstream>
#include <fstream>

using Coefficient = double;
class UnivariatePolynomial {
public:
    UnivariatePolynomial() = default;
    // constructor from an initializer list of coefficients
    UnivariatePolynomial(std::vector<Coefficient>);

    // the degree of the polynomial; for simplicity, we will let the degree of
    // the zero polynomial be -1
    int degree() const;

    void sCoefficient(std::vector<Coefficient> coef);
    
    // change the symbol for the polynomial such as 'y' or 'x'
    void setSymbol(char c);
    // get the symbol
    char symbol() const;

    // return the derivative of the polynomial
    UnivariatePolynomial derivative() const;

    // addition operation with another polynomial
    UnivariatePolynomial operator+(const UnivariatePolynomial&) const;

    // multiplication with a scalar
    UnivariatePolynomial operator*(Coefficient) const;


    // return its coefficients
    // note that we have both a const and non-const version
    // the const version is needed when the object is const
    // this is an example of method overloading
    const std::vector<Coefficient>& coeffcients() const;
    std::vector<Coefficient>& coeffcients();


private:
    std::vector<Coefficient> _coef;
    // default initialization via assignment
    char _symbol = 'x';
};

// overload the output operator
// note that the polynomial parameter is const, so we can only use const methods on it
std::ostream& operator<< (std::ostream& out, const UnivariatePolynomial& polynomial) {
    // --- Your code here
    std::vector<Coefficient> access_Coefs = polynomial.coeffcients();
    int t = 0;
    for(int i=0;i<access_Coefs.size()-1;i++){
        if(i==0 && access_Coefs[i]!=0) {
            out<<access_Coefs[i]<<" "<<'+';
            t = 1;
        }
        else if(i==1 && access_Coefs[i]!=0) {
            if(t == 1)   out<<std::fixed<<std::setprecision(1)<<" "<<access_Coefs[i]<<polynomial.symbol()<<" "<<'+';
            else{

                out<<std::fixed<<std::setprecision(1)<<access_Coefs[i]<<polynomial.symbol()<<" "<<'+';

                t = 1;

                } 
            }
        else if(i>1 && access_Coefs[i]!=0){
            if(t == 1)    out<<std::fixed<<std::setprecision(1)<<" "<<access_Coefs[i]<<polynomial.symbol()<<'^'<<i<<" "<<'+';
            else{
                out<<std::fixed<<std::setprecision(1)<<access_Coefs[i]<<polynomial.symbol()<<'^'<<i<<" "<<'+';
                t =1;


            }
        }
    }
    out<<std::fixed<<std::setprecision(1)<<" "<<access_Coefs[access_Coefs.size()-1]<<polynomial.symbol()<<'^'<<access_Coefs.size()-1;
    // --- 

    return out; // return std::ostream so we can chain calls to operator<<
}

// similarly for the input stream operator
// a bit tricky because we want to only read a single line for our coefficients
// the next line belongs to the next polynomial
std::istream& operator>> (std::istream& input, UnivariatePolynomial& polynomial) {
    // --- Your code here
    std::string str;
    std::vector<Coefficient> setCoef;

    getline(input,str);
    std::stringstream sinput(str);
    Coefficient element;
    while(sinput>>element)  setCoef.emplace_back(element);
    // --- 
    polynomial.sCoefficient(setCoef);
    return input;
}


// implementation of the constructor
UnivariatePolynomial::UnivariatePolynomial(std::vector<Coefficient> l) {
    // --- Your code here
    _coef = l;
    // ---
}

int UnivariatePolynomial::degree() const {
    // --- Your code here
    return _coef.size() - 1;
    // ---
}

void UnivariatePolynomial::setSymbol(char c) {
    _symbol = c;
}

char UnivariatePolynomial::symbol() const {
    return _symbol;
}

void UnivariatePolynomial::sCoefficient(std::vector<Coefficient> coef){
    _coef = coef;
}

UnivariatePolynomial UnivariatePolynomial::derivative() const {
    // --- Your code here
    std::vector<Coefficient> nCoefficient;
    int size = _coef.size();
    if(size<2) return nCoefficient;

    else{
        for(int i=1;i<size;i++){
            nCoefficient.emplace_back(_coef[i]*i);
        }
    }
    UnivariatePolynomial p(nCoefficient);
    // ---
    return p;
}

UnivariatePolynomial UnivariatePolynomial::operator+(const UnivariatePolynomial& p) const {
    // --- Your code here
    int size_l = this->_coef.size();

    std::vector<Coefficient> p_coef = p.coeffcients();
    int size_s = p_coef.size();
    std::vector<Coefficient> sum_Poly;
    if(size_l>=size_s){
        sum_Poly = this->_coef;
        for(int i=0;i<size_s;i++){
            sum_Poly[i]=sum_Poly[i]+p_coef[i];
        }
    }
    else{
        sum_Poly = p_coef;
        for(int i=0;i<size_l;i++){
            sum_Poly[i]=sum_Poly[i]+this->_coef[i];
        }
    }
    UnivariatePolynomial pre(sum_Poly);
    return pre;
    // ---
}

// multiplication with a scalar
UnivariatePolynomial UnivariatePolynomial::operator*(Coefficient scalar) const {
    // --- Your code here
    std::vector<Coefficient> newCoef=this->coeffcients();
    for(int i=0;i<this->_coef.size();i++){
        newCoef[i]=scalar*newCoef[i];
    }
    UnivariatePolynomial p(newCoef);
    return p;

    // ---
}

const std::vector<Coefficient>& UnivariatePolynomial::coeffcients() const {
    return _coef;
}

std::vector<Coefficient>& UnivariatePolynomial::coeffcients() {
    return _coef;
}

int main() {
    UnivariatePolynomial p1{std::vector<Coefficient>{1.5, 0.2, 0, 5.5}};
   
    // coefficients should be printed to 1 decimal place
    // do not print monomials with 0 coefficient
    // monomials with exponent above 1 should have ^exponent behind the symbol

    // make sure these prints to cout are commented out when submitting, or they will make your answer wrong
    // should print 1.5 + 0.2x + 5.5x^3
    // std::cout << p1 << std::endl;

    std::vector<Coefficient> pCoef{-0.1,0,-1.4};
    UnivariatePolynomial p2(pCoef);
    // --- Your code here


    // ---

    // should print -0.1 + -1.4x^2
    // std::cout << p2 << std::endl;

    // should print 0.2 + 16.5x^2
    // std::cout << p1.derivative() << std::endl;

    // should print 1.2 + 0.2x + -4.2x^2 + 5.5^3
    // std::cout << p1 + p2 * 3 << std::endl;


    std::ifstream input{"input.txt"};
    std::ofstream output{"output.txt"};

    output << p1 + p2 * 3 << std::endl;
    UnivariatePolynomial p_total;
    while (input.peek() != std::ifstream::traits_type::eof()) {
        UnivariatePolynomial p;
        input >> p;
        output << p << std::endl;
        output << p.derivative() << std::endl;
        p_total = p_total + p;
    }
    output << p_total << std::endl;
    output << p_total.derivative() << std::endl; 
    return 0;
}