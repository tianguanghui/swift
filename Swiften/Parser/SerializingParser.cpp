#include "Swiften/Parser/SerializingParser.h"
#include "Swiften/Serializer/XML/XMLTextNode.h"
#include "Swiften/Base/foreach.h"
#include <iostream>

namespace Swift {

SerializingParser::SerializingParser() {
}

void SerializingParser::handleStartElement(const String& tag, const String&  ns, const AttributeMap& attributes) {
	boost::shared_ptr<XMLElement> element(new XMLElement(tag, ns));
	for (AttributeMap::const_iterator i = attributes.begin(); i != attributes.end(); ++i) {
		element->setAttribute((*i).first, (*i).second);
	}

	if (elementStack_.empty()) {
		rootElement_ = element;
	}
	else {
		(*(elementStack_.end() - 1))->addNode(element);
	}
	elementStack_.push_back(element);
}

void SerializingParser::handleEndElement(const String&, const String&) {
	assert(!elementStack_.empty());
	elementStack_.pop_back();
}

void SerializingParser::handleCharacterData(const String& data) {
	if (!elementStack_.empty()) {
		(*(elementStack_.end()-1))->addNode(boost::shared_ptr<XMLTextNode>(new XMLTextNode(data)));
	}
}

String SerializingParser::getResult() const {
	return (rootElement_ ? rootElement_->serialize() : "");
}

}
