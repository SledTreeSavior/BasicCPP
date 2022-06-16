// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

//here i tried a simple test of what would happen when all of the bits are the same.
//it functions as it is supposed to, outputting zero each time step runs because XORs
//of any identicle bits will return zero.
//
//the test of generate with the same bits will also output zero because temp never
//goes above zero.
BOOST_AUTO_TEST_CASE(sixteenBitsOfZeros) {
	
	FibLFSR l("0000000000000000");
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);

	FibLFSR l2("0000000000000000");
	BOOST_REQUIRE(l2.generate(16) == 0);
}

//here i tried a more complex test of what would happen when each bit alternates in value.
//after tracing, i found that the XOR will always return zero until one of those zeros
//replaces a tap bit that was previously one. after the tap bit is replaced, the pattern
//of outputting zeros stops. the program correctly handles this.
//
//the test of generate with the sames alternating bits will output eighteen because
//the value of temp will go from 0->1->2->4->9->18 because of the specific pattern
//of ones and zeros after the first one is outputted.
BOOST_AUTO_TEST_CASE(sixteenBitsOfAlternating) {

	FibLFSR l("0101010101010101");
	BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 0);
        BOOST_REQUIRE(l.step() == 1);
        BOOST_REQUIRE(l.step() == 0);

        FibLFSR l2("0101010101010101");
        BOOST_REQUIRE(l2.generate(16) == 18);

}
