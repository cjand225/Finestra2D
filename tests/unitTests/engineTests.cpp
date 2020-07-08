#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <Engine.hpp>

BOOST_AUTO_TEST_CASE( PHtest1 )
{
    // reports 'error in "test1": test 2 == 1 failed'
    BOOST_CHECK( 2 == 1 );
}
