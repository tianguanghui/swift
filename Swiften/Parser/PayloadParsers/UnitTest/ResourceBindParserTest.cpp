#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "Swiften/Parser/PayloadParsers/ResourceBindParser.h"
#include "Swiften/Parser/PayloadParsers/UnitTest/PayloadParserTester.h"

using namespace Swift;

class ResourceBindParserTest : public CppUnit::TestFixture
{
		CPPUNIT_TEST_SUITE(ResourceBindParserTest);
		CPPUNIT_TEST(testParse_JID);
		CPPUNIT_TEST(testParse_Resource);
		CPPUNIT_TEST_SUITE_END();

	public:
		ResourceBindParserTest() {}

		void testParse_JID() {
			ResourceBindParser testling;
			PayloadParserTester parser(&testling);

			CPPUNIT_ASSERT(parser.parse("<bind xmlns='urn:ietf:params:xml:ns:xmpp-bind'><jid>somenode@example.com/someresource</jid></bind>"));

			ResourceBind* payload = dynamic_cast<ResourceBind*>(testling.getPayload().get());
			CPPUNIT_ASSERT_EQUAL(JID("somenode@example.com/someresource"), payload->getJID());
		}

		void testParse_Resource() {
			ResourceBindParser testling;
			PayloadParserTester parser(&testling);

			CPPUNIT_ASSERT(parser.parse("<bind xmlns='urn:ietf:params:xml:ns:xmpp-bind'><resource>someresource</resource></bind>"));

			ResourceBind* payload = dynamic_cast<ResourceBind*>(testling.getPayload().get());
			CPPUNIT_ASSERT_EQUAL(String("someresource"), payload->getResource());
		}
};

CPPUNIT_TEST_SUITE_REGISTRATION(ResourceBindParserTest);
