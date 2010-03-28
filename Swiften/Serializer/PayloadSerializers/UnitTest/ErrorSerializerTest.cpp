#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Swiften/Serializer/PayloadSerializers/ErrorSerializer.h"

using namespace Swift;

class ErrorSerializerTest : public CppUnit::TestFixture
{
		CPPUNIT_TEST_SUITE(ErrorSerializerTest);
		CPPUNIT_TEST(testSerialize);
		CPPUNIT_TEST_SUITE_END();

	public:
		ErrorSerializerTest() {}

		void testSerialize() {
			ErrorSerializer testling;
			boost::shared_ptr<ErrorPayload> error(new ErrorPayload(ErrorPayload::BadRequest, ErrorPayload::Cancel, "My Error"));

			CPPUNIT_ASSERT_EQUAL(String("<error type=\"cancel\"><bad-request xmlns=\"urn:ietf:params:xml:ns:xmpp-stanzas\"/><text xmlns=\"urn:ietf:params:xml:ns:xmpp-stanzas\">My Error</text></error>"), testling.serialize(error));
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(ErrorSerializerTest);
