#include "Swiften/Parser/PlatformXMLParserFactory.h"

#include <cassert>

#ifdef HAVE_LIBXML
#include "Swiften/Parser/LibXMLParser.h"
#else
#include "Swiften/Parser/ExpatParser.h"
#endif


namespace Swift {

PlatformXMLParserFactory::PlatformXMLParserFactory() {
}

XMLParser* PlatformXMLParserFactory::createXMLParser(XMLParserClient* client) {
#ifdef HAVE_LIBXML
	return new LibXMLParser(client);
#else
	return new ExpatParser(client);
#endif
}

}
