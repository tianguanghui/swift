#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Swiften/StringCodecs/Base64.h"

using namespace Swift;

class Base64Test : public CppUnit::TestFixture
{
		CPPUNIT_TEST_SUITE(Base64Test);
		CPPUNIT_TEST(testEncode);
		CPPUNIT_TEST(testEncode_NonAscii);
		CPPUNIT_TEST(testDecode);
		CPPUNIT_TEST_SUITE_END();

	public:
		Base64Test() {}

		void testEncode() {
			String result(Base64::encode("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"));
			CPPUNIT_ASSERT_EQUAL(String("QUJDREVGR0hJSktMTU5PUFFSU1RVVldYWVphYmNkZWZnaGlqa2xtbm9wcXJzdHV2d3h5ejEyMzQ1Njc4OTA="), result);
		}

		void testEncode_NonAscii() {
			String result(Base64::encode(ByteArray("\x42\x06\xb2\x3c\xa6\xb0\xa6\x43\xd2\x0d\x89\xb0\x4f\xf5\x8c\xf7\x8b\x80\x96\xed")));
			CPPUNIT_ASSERT_EQUAL(String("QgayPKawpkPSDYmwT/WM94uAlu0="), result);
    }

		void testDecode() {
			ByteArray result(Base64::decode("QUJDREVGR0hJSktMTU5PUFFSU1RVVldYWVphYmNkZWZnaGlqa2xtbm9wcXJzdHV2d3h5ejEyMzQ1Njc4OTA="));
			CPPUNIT_ASSERT_EQUAL(ByteArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"), result);
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(Base64Test);
