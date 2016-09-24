//Link to Boost
#define BOOST_TEST_DYN_LINK

//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "BaseClassModule"

//VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "inputHandler.hpp"
BOOST_AUTO_TEST_SUITE( test_suite1 )
BOOST_AUTO_TEST_CASE( test_case_1 )
{
 BOOST_CHECK( true );
}
#if ON
BOOST_AUTO_TEST_CASE( test_case_2 )
{
 searchers::input::inputHandler obj1{1,"Help"};
 searchers::input::inputHandler obj2{1,"Help"};
 BOOST_CHECK( obj1 == obj2 );
}
#endif
BOOST_AUTO_TEST_SUITE_END()
