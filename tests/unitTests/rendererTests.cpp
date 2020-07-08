#include <boost/test/unit_test.hpp>
#include <Renderer/Renderer.hpp>

BOOST_AUTO_TEST_CASE( PHtest2 )
{
    // reports 'error in "test1": test 2 == 1 failed'
    BOOST_CHECK( 2 == 1 );
}
