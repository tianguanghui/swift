#ifndef SWIFTEN_ResourceBindParser_H
#define SWIFTEN_ResourceBindParser_H

#include "Swiften/Elements/ResourceBind.h"
#include "Swiften/Parser/GenericPayloadParser.h"

namespace Swift {
	class ResourceBindParser : public GenericPayloadParser<ResourceBind> {
		public:
			ResourceBindParser();

			virtual void handleStartElement(const String& element, const String&, const AttributeMap& attributes);
			virtual void handleEndElement(const String& element, const String&);
			virtual void handleCharacterData(const String& data);

		private:
			int level_;
			bool inJID_;
			bool inResource_;
			String text_;
	};
}

#endif
