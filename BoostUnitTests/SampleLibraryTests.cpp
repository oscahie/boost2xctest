//
//  SampleLibraryTests.cpp
//
//  Created by Oscar Hierro - https://github.com/oscahie
//

#import "SampleLibrary.hpp"
#import <boost/test/unit_test.hpp>

// NOTE: This name must be unique within the entire test suite
BOOST_AUTO_TEST_SUITE(SampleLibraryTests)

struct F {
    F() {};
    ~F() {};
};

// an always passing test
BOOST_FIXTURE_TEST_CASE(test_two_plus_three_is_5, F)
{
    BOOST_CHECK_EQUAL(acme_sum(2, 3), 5);
}

// an always failing test
BOOST_FIXTURE_TEST_CASE(test_two_plus_three_is_7, F)
{
    BOOST_CHECK_EQUAL(acme_sum(2, 3), 7);
}

// a test case whose name does not begin with the 'test' prefix
BOOST_FIXTURE_TEST_CASE(a_differently_named_test_case, F)
{
    BOOST_CHECK_EQUAL(acme_sum(2, 2), 4);
}

BOOST_AUTO_TEST_SUITE_END()
