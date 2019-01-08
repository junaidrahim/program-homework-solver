#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../../include/poly.h"
#include "../../include/BasisPolynomial.h"
#include "../../include/LagrangePolynomial.h"

TEST_CASE("Testing all functions of Program Homework Solver with normal inputs", "[ALL]"){

    SECTION ("Testing poly.h") {
        poly p;
        p.add_to_numerator("x");
        p.add_to_numerator("y");
        p.add_to_numerator("z");

        p.add_to_denominator(1);
        p.add_to_denominator(2);
        p.add_to_denominator(3);

        std::vector<std::string> n = {"x","y","z"};
        std::vector<int> d = {1,2,3};

        REQUIRE(p.numerators == n);
        REQUIRE(p.denominators == d);
    }

    SECTION ("Testing BasisPolynomial.h") {
        std::vector<int> x = {1,2,3,4};
        BasisPolynomial b(x);

        std::vector<poly> basis_polynomials = b.get_all_basis_polynomials();

        // checking the numerators
        REQUIRE( basis_polynomials[0].numerators == std::vector<std::string>{"x-2", "x-3", "x-4"} );
        REQUIRE( basis_polynomials[1].numerators == std::vector<std::string>{"x-1", "x-3", "x-4"} );
        REQUIRE( basis_polynomials[2].numerators == std::vector<std::string>{"x-1", "x-2", "x-4"} );
        REQUIRE( basis_polynomials[3].numerators == std::vector<std::string>{"x-1", "x-2", "x-3"} );

        // checking the denominators
        REQUIRE( basis_polynomials[0].denominators == std::vector<int>{ -1, -2, -3 } );
        REQUIRE( basis_polynomials[1].denominators == std::vector<int>{ 1, -1, -2 } );
        REQUIRE( basis_polynomials[2].denominators == std::vector<int>{ 2, 1, -1 } );
        REQUIRE( basis_polynomials[3].denominators == std::vector<int>{ 3, 2, 1 } );
    }

    SECTION("Testing LagrangePolynomial.h"){
        std::vector<int> x = {1,2,3,4};
        std::vector<int> y = {1,4,9,16};

        BasisPolynomial b(x);
        std::vector<poly> basis_polynomials = b.get_all_basis_polynomials();

        LagrangePolynomial lagrange_polynomial;
        std::vector<LagrangePolynomial::element> lp_results = lagrange_polynomial.get_lagrange_polynomial(y,basis_polynomials);

        REQUIRE( lp_results[0].multiple == 1 );
        REQUIRE( lp_results[1].multiple == 4 );
        REQUIRE( lp_results[2].multiple == 9 );
        REQUIRE( lp_results[3].multiple == 16 );

        REQUIRE( lp_results[0].p == std::vector<std::string>{"x-2", "x-3", "x-4"} );
        REQUIRE( lp_results[1].p == std::vector<std::string>{"x-1", "x-3", "x-4"} );
        REQUIRE( lp_results[2].p == std::vector<std::string>{"x-1", "x-2", "x-4"} );
        REQUIRE( lp_results[3].p == std::vector<std::string>{"x-1", "x-2", "x-3"} );

        REQUIRE( lp_results[0].denominator == -6 );
        REQUIRE( lp_results[1].denominator == 2 );
        REQUIRE( lp_results[2].denominator == -2 );
        REQUIRE( lp_results[3].denominator == 6 );
    }

}